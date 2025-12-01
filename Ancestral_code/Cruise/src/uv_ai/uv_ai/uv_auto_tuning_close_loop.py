#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
水下机器人全自动推力曲线调整系统
功能：通过开环控制测试电机推力，自动调整推力曲线参数，使机器人运动更平滑
电机编号：0(左上)，1(右上)，2(左垂推)，3(右垂推)，4(左后)，5(右后)
"""

import rclpy
from rclpy.node import Node
import time
import math
from math import cos, radians
import json
import numpy as np
from collections import deque
import signal  # 添加信号处理

from uv_msgs.msg import RobotAxis, RobotMotionController, ThrustCurve, ThrustCurves, TargetPosDown
from uv_control_py import Curve
from uv_control_py import Serial


AllowedError = {  # 位置容许误差
    "x": 0.02,
    "y": 0.02,
    "z": 0.02,
    "rz": 1.3
}

Trust_List=[-1500, -750, 0, 750, 1500]

kp = 5

class AutoThrustTuner(Node):
    def __init__(self, name):
        super().__init__(name)
        self.get_logger().info("全自动推力曲线调整器初始化中...")
        
        # 初始化参数
        self.initialize_parameters()
        
        # 设置信号处理，用于紧急停止
        signal.signal(signal.SIGINT, self.signal_handler)
        signal.signal(signal.SIGTERM, self.signal_handler)
        
        # 订阅机器人运动状态
        self.motion_sub = self.create_subscription(
            RobotMotionController, "motion_controller", self.motion_callback, 10)
        
        # 创建发布者，用于发布调整后的推力曲线
        self.curve_pub = self.create_publisher(ThrustCurves, "curves", 10)
        
        # 创建开环推力发布者
        self.thrust_pub = self.create_publisher(RobotAxis, "openloop_thrust", 10)

        # 创建目标位置发布者
        self.target_pos_down_pub = self.create_publisher(TargetPosDown, "target_pos_down", 10)
        
        # 初始化曲线管理器
        self.initialize_curve_manager()
        
        self.get_logger().info("全自动推力曲线调整器初始化完成！")

        # 等待移动至指定位置
    def move_wait(self):
        cnt = 0
        time.sleep(0.5)
        while True:
            judge = 0
            if abs(self.current_motion.tpos_inbase.x) > AllowedError["x"]:
                judge += 1
            if abs(self.current_motion.tpos_inbase.y) > AllowedError["y"]:
                judge += 1
            if abs(self.current_motion.tpos_inbase.z) > AllowedError["z"]:
                judge += 1
            if abs(self.current_motion.tpos_inbase.rz) > AllowedError["rz"]:
                judge += 1

            if judge == 0:  # 进入容许范围
                return True

            if cnt > 200:  # 超时退出
                return False

            cnt += 1
            time.sleep(0.05)

    def move_to_pos(self, pos):

        if self.should_stop:
            return False

        distance = abs(pos - self.current_motion.tpos_inbase.z)
        self.get_logger().info(f"移动到位置 {pos}，距离 {distance}")
        times = distance / 0.1
        for i in range(int(times)):
            self.target_pos_down_pub.publish(TargetPosDown(target_pos=pos))
            self.move_wait()
        self.move_wait()
        num = 0
        while True:
            if abs(pos - self.current_motion.tpos_inbase.z) < 0.02:
                num += 1
            time.sleep(0.5)
            if num > 3:
                break
        self.get_logger().info("到达目标位置")



    
    def signal_handler(self, signum, frame):
        """信号处理函数，用于紧急停止"""
        self.get_logger().info(f"收到信号 {signum}，执行紧急停止")
        self.emergency_stop()
        
    def emergency_stop(self):
        """紧急停止所有电机"""
        self.get_logger().info("执行紧急停止！")
        
        # 立即停止所有推力
        stop_msg = RobotAxis()
        stop_msg.x = 0
        stop_msg.y = 0
        stop_msg.z = 0
        stop_msg.rz = 0
        self.thrust_pub.publish(stop_msg)        
        # 保存当前状态
        self.save_state()
        
        # 设置停止标志
        self.should_stop = True
        
        self.get_logger().info("紧急停止完成，状态已保存")
    
    def initialize_parameters(self):
        """初始化所有必要的参数"""
        # 电机编号定义
        self.motor_pairs = [(0, 1), (1, 5), (5, 4)]  # 需要调整的电机对
        self.motor_positions = ["左上", "右上", "左垂推", "右垂推", "左后", "右后"]
        
        # 测试参数
        self.test_force_range = range(0, -1600, -100)  # 测试推力范围新这个地方要改
        self.stabilization_time = 0.5  # 稳定时间(秒)
        self.test_duration = 0.1  # 测试时间(秒)
        
        # 当前机器人状态
        self.current_motion = None
        self.test_results = {}
        
        # 中断和恢复相关状态
        self.current_motor_pair_index = 0  # 当前正在调整的电机对索引
        self.current_force_index = 0       # 当前正在测试的推力索引
        self.is_paused = False             # 是否暂停状态
        self.should_stop = False           # 是否应该停止
    
    def initialize_curve_manager(self):
        """初始化推力曲线管理器"""
        # 获取曲线文件路径
        self.curve_path = '/home/nvidia/Workspace/Cruise/datas/thrust_cureves.json'
        
        # 创建串口写入器（这里不实际使用，仅为了初始化Curve类）
        dummy_serial = type('obj', (object,), {"write": lambda *args: None})
        
        # 初始化曲线管理器
        self.curve_manager = Curve.CURVE(dummy_serial, self.curve_path)
        
        # 加载当前曲线参数
        try:
            self.curve_manager.fileread()
            self.get_logger().info(f"成功加载推力曲线参数文件: {self.curve_path}")
        except Exception as e:
            self.get_logger().error(f"加载推力曲线参数失败: {e}")
            # 使用默认参数
            self.curve_manager.curves_dic = Curve.CURVE_DIC_INIT
            self.curve_manager.dic2class()
    
    def motion_callback(self, data):
        """接收机器人运动状态数据"""
        self.current_motion = data
    
    def set_motor_zero(self, exclude_pair=None):
        """将除指定电机对外的所有电机推力设为0"""
        # 使用零推力曲线参数
        zero_curves = self.curve_manager.curves_dic.copy()
        
        # 如果指定了电机对，则不将这对电机设为零
        if exclude_pair:
            # 恢复指定电机对的原始参数
            for motor_idx in exclude_pair:
                motor_name = f"m{motor_idx}"
                zero_curves[motor_name] = self.curve_manager.curves_dic[motor_name].copy()
        
        # 更新曲线参数
        self.curve_manager.curves_dic = zero_curves
        self.curve_manager.dic2class()
        
        # 保存曲线
        self.apply_curves()
    
    def apply_thrust(self, motor_pair, force):
        """对指定电机对施加推力，通过整体控制指令间接实现单个电机的控制"""
        if self.should_stop:
            stop_msg = RobotAxis()
            stop_msg.x = 0
            stop_msg.y = 0
            stop_msg.rz = 0
            self.thrust_pub.publish(stop_msg)
            return False
        # 发布开环推力指令
        thrust_msg = RobotAxis()
        
        # 用户需求：控制单个电机的推力，通过force反推向下位机发送的总体推力
        # 因为程序架构里没有设计上位机直接控制单个电机的功能
        # 所以我们需要通过整体控制指令来间接实现单个电机的控制
        
        # 定义常量
        A1 = 0.20489
        A2 = 0.19341
        B = 0.45725
        C = 0.20475
        
        # 根据电机对和目标推力，计算需要的6自由度指令
        # 对于每个电机对，我们通过组合不同的自由度指令来实现单个电机的控制
        if motor_pair == (0, 1):  # 左右上电机
            # 目标：控制电机0的推力为force，电机1的推力为0
            # 根据推力分配公式：
            # motor0 = -A2*x/B + C*y + rz/B
            # motor1 = A2*x/B + C*y - rz/B
            
            # 解方程组：
            # -A2*x/B + C*y + rz/B = force
            # A2*x/B + C*y - rz/B = 0
            # 将两个方程相加：2*C*y = force → y = force/(2*C)
            # 将两个方程相减：-2*A2*x/B + 2*rz/B = force → -A2*x + rz = force*B/2
            # 我们选择x=0，这样rz = force*B/2
            
            y = force / (2 * C)
            rz = force * B / 2
            
            # 设置推力指令
            thrust_msg.y = y
            thrust_msg.rz = rz
            
        elif motor_pair == (1, 5):  # 右上前后电机
            # 目标：控制电机1的推力为force，电机5的推力为0
            # 根据推力分配公式：
            # motor1 = A2*x/B + C*y - rz/B
            # motor5 = A1*x/B - C*y + rz/B
            
            # 解方程组：
            # A2*x/B + C*y - rz/B = force
            # A1*x/B - C*y + rz/B = 0
            # 将两个方程相加：(A2+A1)*x/B = force → x = force*B/(A2+A1)
            # 将两个方程相减：2*C*y - 2*rz/B = force → C*y - rz/B = force/2
            # 我们选择y=0，这样rz = -force*B/2
            
            x = force * B / (A2 + A1)
            rz = -force * B / 2
            
            # 设置推力指令
            thrust_msg.x = x
            thrust_msg.rz = rz
            
        elif motor_pair == (5, 4):  # 左右后电机
            # 目标：控制电机5的推力为force，电机4的推力为0
            # 根据推力分配公式：
            # motor5 = A1*x/B - C*y + rz/B
            # motor4 = -A1*x/B - C*y - rz/B
            
            # 解方程组：
            # A1*x/B - C*y + rz/B = force
            # -A1*x/B - C*y - rz/B = 0
            # 将两个方程相加：-2*C*y = force → y = -force/(2*C)
            # 将两个方程相减：2*A1*x/B + 2*rz/B = force → A1*x + rz = force*B/2
            # 我们选择x=0，这样rz = force*B/2
            
            y = -force / (2 * C)
            rz = force * B / 2
            
            # 设置推力指令
            thrust_msg.y = y
            thrust_msg.rz = rz
        
        # 发布推力指令
        self.thrust_pub.publish(thrust_msg)
    
    def apply_equal_thrust(self, motor_pair, force):
        """对指定电机对施加相同的推力，通过整体控制指令间接实现"""

        if self.should_stop:
            return False
        # 发布开环推力指令
        thrust_msg = RobotAxis()
        
        # 定义常量
        A1 = 0.20489
        A2 = 0.19341
        B = 0.45725
        C = 0.20475
        
        # 根据电机对和目标推力，计算需要的6自由度指令
        # 目标：使电机对中的两个电机都产生相同的推力 force
        if motor_pair == (0, 1):  # 左右上电机
            # 目标：控制电机0和电机1的推力都为force
            # 根据推力分配公式：
            # motor0 = -A2*x/B + C*y + rz/B = force
            # motor1 = A2*x/B + C*y - rz/B = force
            
            # 解方程组：
            # -A2*x/B + C*y + rz/B = force
            # A2*x/B + C*y - rz/B = force
            # 将两个方程相加：2*C*y = 2*force → y = force/C
            # 将两个方程相减：-2*A2*x/B + 2*rz/B = 0 → -A2*x + rz = 0 → rz = A2*x
            # 我们可以选择x=0，这样rz=0，简化控制
            
            y = force / C
            
            # 设置推力指令
            thrust_msg.y = y
            
        elif motor_pair == (1, 5):  # 右上前后电机
            # 目标：控制电机1和电机5的推力都为force
            # 根据推力分配公式：
            # motor1 = A2*x/B + C*y - rz/B = force
            # motor5 = A1*x/B - C*y + rz/B = force
            
            # 解方程组：
            # A2*x/B + C*y - rz/B = force
            # A1*x/B - C*y + rz/B = force
            # 将两个方程相加：(A2+A1)*x/B = 2*force → x = 2*force*B/(A2+A1)
            # 将两个方程相减：2*C*y - 2*rz/B = 0 → C*y = rz/B → rz = B*C*y
            # 我们可以选择y=0，这样rz=0，简化控制
            
            x = 2 * force * B / (A2 + A1)
            
            # 设置推力指令
            thrust_msg.x = x
            
        elif motor_pair == (5, 4):  # 左右后电机
            # 目标：控制电机5和电机4的推力都为force
            # 根据推力分配公式：
            # motor5 = A1*x/B - C*y + rz/B = force
            # motor4 = -A1*x/B - C*y - rz/B = force
            
            # 解方程组：
            # A1*x/B - C*y + rz/B = force
            # -A1*x/B - C*y - rz/B = force
            # 将两个方程相加：-2*C*y = 2*force → y = -force/C
            # 将两个方程相减：2*A1*x/B + 2*rz/B = 0 → A1*x + rz = 0 → rz = -A1*x
            # 我们可以选择x=0，这样rz=0，简化控制
            
            y = -force / C
            
            # 设置推力指令
            thrust_msg.y = y
        
        # 发布推力指令
        self.thrust_pub.publish(thrust_msg)

    def measure_angular_acceleration(self):
        """
        测量角加速度
        过程将持续test_duration秒
        """
        # 记录初始角速度
        initial_rz = self.current_motion.imu.spd.rz if self.current_motion else 0.0
        
        # 记录开始时间
        start_time = time.time()
        
        # 收集数据
        rz_values = []
        times = []
        
        # 持续测试一段时间
        while time.time() - start_time < self.test_duration:
            if self.current_motion:
                rz_values.append(self.current_motion.imu.spd.rz)
                times.append(time.time() - start_time)
            time.sleep(0.01)  # 100Hz采样
        
        # 计算角加速度
        if len(rz_values) > 1:
            # 使用线性回归计算角加速度
            coeffs = np.polyfit(times, rz_values, 1)
            angular_acceleration = coeffs[0]  # 角速度变化率即为角加速度
        else:
            angular_acceleration = 0.0
        
        return angular_acceleration
    
    def measure_angular_velocity(self):
        """测量角速度"""
        # 记录初始角速度
        initial_rz = self.current_motion.imu.spd.rz if self.current_motion else 0.0
        
        # 记录开始时间
        start_time = time.time()
        
        # 收集数据
        rz_values = []
        times = []
        
        # 持续测试一段时间
        while time.time() - start_time < self.test_duration:
            if self.current_motion:
                rz_values.append(self.current_motion.imu.spd.rz)
                times.append(time.time() - start_time)
            time.sleep(0.01)  # 100Hz采样
        
        # 计算角速度
        if len(rz_values) > 1:
            # 使用线性回归计算角速度
            coeffs = np.polyfit(times, rz_values, 1)
            angular_velocity = coeffs[0]  # 角速度变化率即为角速度
        else:
            angular_velocity = 0.0
        
        return angular_velocity
    
    def thrust_allocate(self, askedthrust):
        """
        推力分配函数
        
        参数:
            askedthrust (list or np.array): 6个自由度的控制指令 [x, y, z, rx, ry, rz]
        
        返回:
            list: 分配给6个推进器的推力 [motor0, motor1, motor2, motor3, motor4, motor5]
        """
        # 定义常量
        __A_1 = 0.20489
        __A_2 = 0.19341
        __B = 0.45725
        __C = 0.20475
        __2b = 0.22000
        
        # 初始化电机推力数组
        motorthrust = [0.0] * 6
        
        # 根据C代码中的公式进行推力分配
        motorthrust[0] = -__A_2 * askedthrust[0] / __B + __C * askedthrust[1] + askedthrust[5] / __B
        motorthrust[1] = __A_2 * askedthrust[0] / __B + __C * askedthrust[1] - askedthrust[5] / __B
        motorthrust[2] = -0.5 * askedthrust[2] + askedthrust[4] / __2b
        motorthrust[3] = -0.5 * askedthrust[2] - askedthrust[4] / __2b
        motorthrust[4] = -__A_1 * askedthrust[0] / __B - __C * askedthrust[1] - askedthrust[5] / __B
        motorthrust[5] = __A_1 * askedthrust[0] / __B - __C * askedthrust[1] + askedthrust[5] / __B
        
        return motorthrust
    
    def thrust_deallocate(self, motor_thrusts, direction):
        """
        推力逆运算函数 - 从单个电机的推力反推某个方向上的整体推力
        
        参数:
            motor_thrusts (list): 6个推进器的推力 [motor0, motor1, motor2, motor3, motor4, motor5]
            direction (str): 要计算的方向，可选值为 'x', 'y', 'z', 'rx', 'ry', 'rz'
        
        返回:
            float: 指定方向上的整体推力
        """
        # 定义常量
        __A_1 = 0.20489
        __A_2 = 0.19341
        __B = 0.45725
        __C = 0.20475
        __2b = 0.22000
        
        # 方向索引映射
        direction_map = {'x': 0, 'y': 1, 'z': 2, 'rx': 3, 'ry': 4, 'rz': 5}
        
        if direction not in direction_map:
            self.get_logger().error(f"无效的方向: {direction}，可选值为 'x', 'y', 'z', 'rx', 'ry', 'rz'")
            return 0.0
        
        idx = direction_map[direction]
        
        # 根据不同方向计算整体推力
        if idx == 0:  # x方向
            # 从分配公式反解x方向的整体推力
            # 基于motor1和motor5的方程联立求解
            # (motor1 - motor5) = (2*__A_2 + 2*__A_1) * askedthrust[0] / __B
            # 所以 askedthrust[0] = (motor1 - motor5) * __B / (2*__A_2 + 2*__A_1)
            return (motor_thrusts[1] - motor_thrusts[5]) * __B / (2*__A_2 + 2*__A_1)
        
        elif idx == 1:  # y方向
            # 从分配公式反解y方向的整体推力
            # 基于motor0和motor4的方程联立求解
            # (motor0 + motor4) = 2*__C * askedthrust[1]
            # 所以 askedthrust[1] = (motor0 + motor4) / (2*__C)
            return (motor_thrusts[0] + motor_thrusts[4]) / (2*__C)
        
        elif idx == 2:  # z方向
            # 从分配公式反解z方向的整体推力
            # motor2 + motor3 = -askedthrust[2]
            return -(motor_thrusts[2] + motor_thrusts[3])
        
        elif idx == 4:  # ry方向 (绕y轴旋转)
            # 从分配公式反解ry方向的整体推力
            # motor2 - motor3 = 2*askedthrust[4] / __2b
            # 所以 askedthrust[4] = (motor2 - motor3) * __2b / 2
            return (motor_thrusts[2] - motor_thrusts[3]) * __2b / 2
        
        elif idx == 5:  # rz方向 (绕z轴旋转)
            # 从分配公式反解rz方向的整体推力
            # (motor0 + motor5 - motor1 - motor4) = 4*askedthrust[5] / __B
            # 所以 askedthrust[5] = (motor0 + motor5 - motor1 - motor4) * __B / 4
            return (motor_thrusts[0] + motor_thrusts[5] - motor_thrusts[1] - motor_thrusts[4]) * __B / 4
        
        else:  # rx方向 (绕x轴旋转)
            # 当前分配函数中没有直接涉及rx方向的控制
            self.get_logger().warning(f"当前推力分配函数中未直接涉及 '{direction}' 方向的控制")
            return 0.0
        
    def limit_parameters(self, params):
        """限制参数在合理范围内"""
        # PWM相关参数范围限制
        params['np_mid'] = max(2000.0, min(3000.0, params['np_mid']))
        params['np_ini'] = max(2500.0, min(3500.0, params['np_ini']))
        params['pp_ini'] = max(2500.0, min(3500.0, params['pp_ini']))
        params['pp_mid'] = max(3000.0, min(4000.0, params['pp_mid']))
        
        # 推力相关参数范围限制
        params['nt_end'] = max(-2000.0, min(-500.0, params['nt_end']))
        params['nt_mid'] = max(-1500.0, min(-250.0, params['nt_mid']))
        params['pt_mid'] = max(250.0, min(1500.0, params['pt_mid']))
        params['pt_end'] = max(500.0, min(2000.0, params['pt_end']))
    
    def save_curves(self):
        """保存并应用新的推力曲线"""
        try:
            # 保存到文件
            self.curve_manager.filesave()
            self.get_logger().info(f"已保存更新后的推力曲线参数到: {self.curve_path}")
            return True
        except Exception as e:
            self.get_logger().error(f"保存推力曲线失败: {e}")
            return False
    def apply_curves(self):
        """保存并应用新的推力曲线"""
        try:
            # 发布更新后的曲线，供其他节点使用
            self.curve_pub.publish(self.curve_manager.curves)
            self.get_logger().info("已发布更新后的推力曲线")
            
            return True
        except Exception as e:
            self.get_logger().error(f"应用推力曲线失败: {e}")
            return False
    
    def tune_motor_pair(self, motor_pair):
        """调整指定电机对的推力曲线，支持从中断点恢复"""
        self.get_logger().info(f"开始调整电机对 {motor_pair[0]}({self.motor_positions[motor_pair[0]]}) 和 {motor_pair[1]}({self.motor_positions[motor_pair[1]]}) ")
        
        # 将其他电机推力设为0
        self.set_motor_zero(exclude_pair=motor_pair)
        
        # 等待稳定
        time.sleep(1.0)
        

        self.get_logger().info("尝试回归原点")
        self.move_to_pos(0.0)

        # 等待回归完成
        time.sleep(1.0)

        force = Trust_List[0]

        self.get_logger().info(f"测试推力: {force}")
            
        # 使用apply_equal_thrust让两个电机输出相同的力
        self.apply_equal_thrust(motor_pair, force)

        num = 0
        times = 0

        #简易p控制器闭环控制
        index_map = {
            0: "pp_ini",
            1: "pp_mid",
            2: "pt_mid",
            3: "pt_end"
        }


        for i in range(4):

            index = index_map.get(i, "default_value")

            while True:
                # 检查是否应该中断
                if self.should_stop:
                    self.get_logger().info("收到停止信号，中断调整流程")
                    self.save_state()
                    return False
                
                # 检查是否应该暂停
                if self.is_paused:
                    self.get_logger().info("收到暂停信号，暂停调整流程")
                    self.save_state()
                    return True

                # 等待稳定
                time.sleep(0.5)
                # 测量角速度
                angular_velocity = self.measure_angular_velocity()
                self.get_logger().info(f"测量到的角速度: {angular_velocity}")
                # 计算误差
                error = abs(angular_velocity)

                if angular_velocity > 0.1:
                    #减小右侧推力
                    self.curve_manager.curves_dic[f"m{motor_pair[1]}"]["index"] -= kp * error
                    self.get_logger().info(f"调整后的pp_ini: {self.curve_manager.curves_dic[f'm{motor_pair[1]}']['index']}")

                elif angular_velocity < -0.1:
                    #增大右侧推力
                    self.curve_manager.curves_dic[f"m{motor_pair[1]}"]["index"] += kp * error
                    self.get_logger().info(f"调整后的pp_ini: {self.curve_manager.curves_dic[f'm{motor_pair[1]}']['index']}")

                else:
                    num += 1
                
                times += 1

                # 保存并应用新的推力曲线
                self.apply_curves()

                # 保存调整日志
                self.save_log()

                if num > 3:
                    break

                if times > 100:
                    self.get_logger().info("调整超时")
                    return False
                    
            
            self.get_logger().info("i调整完成")
            # 保存调整日志
            self.save_log()

        return True

    def run_tuning(self):
        """运行完整的推力曲线调整流程，支持中断和恢复"""
        try:
            # 尝试加载之前的状态
            state_loaded = self.load_state()
            
            # 如果没有加载到状态，从头开始
            if not state_loaded:
                self.current_motor_pair_index = 0
                self.current_force_index = 0
                self.test_results = {}
            
            # 依次调整各电机对，从中断点开始
            for i in range(self.current_motor_pair_index, len(self.motor_pairs)):
                motor_pair = self.motor_pairs[i]
                self.current_motor_pair_index = i  # 更新当前电机对索引
                
                # 检查是否应该中断
                if self.should_stop:
                    self.get_logger().info("收到停止信号，中断调整流程")
                    self.save_state()
                    break
                
                self.get_logger().info(f"开始调整第 {i+1}/{len(self.motor_pairs)} 组电机对: {motor_pair}")
                
                # 调整当前电机对，从中断的推力点开始
                result = self.tune_motor_pair(motor_pair)
                
                # 保存调整日志
                self.save_log()
                
                # 如果返回False表示完全停止，返回True表示暂停或完成
                if result is False:
                    self.get_logger().info("调整被中断")
                    self.save_state()
                    break
                


                # 如果不是最后一个电机对，询问用户是否继续
                if i < len(self.motor_pairs) - 1:
                    user_input = input("\n按回车键继续调整下一组电机对，输入 'pause' 暂停，输入 'quit' 退出: ")
                    
                    if user_input.strip().lower() == 'quit':
                        self.get_logger().info("用户请求退出调整流程")
                        self.should_stop = True
                        self.save_state()
                        # 保存调整日志
                        self.save_log()
                        break
                    elif user_input.strip().lower() == 'pause':
                        self.get_logger().info("用户请求暂停调整流程")
                        self.is_paused = True
                        self.save_state()
                        # 保存调整日志
                        self.save_log()
                        return  # 暂停并退出，等待下次继续
            
            # 如果所有电机对都调整完成
            if not self.should_stop and not self.is_paused:
                self.get_logger().info("所有电机对调整完成！")
                # 清除状态文件和备份文件
                try:
                    import os
                    state_file = '/home/nvidia/Workspace/Cruise/datas/tuning_state.json'
                    backup_file = '/home/nvidia/Workspace/Cruise/datas/tuning_state_backup.json'
                    
                    if os.path.exists(state_file):
                        os.remove(state_file)
                        self.get_logger().info("状态文件已清除")
                    
                    if os.path.exists(backup_file):
                        os.remove(backup_file)
                        self.get_logger().info("状态备份文件已清除")
                except Exception as e:
                    self.get_logger().error(f"清除状态文件失败: {e}")
            
        except Exception as e:
            self.get_logger().error(f"调整过程中发生错误: {e}")
            self.save_state()  # 出错时保存状态
        finally:
        # 立即停止所有推力
            stop_msg = RobotAxis()
            stop_msg.x = 0
            stop_msg.y = 0
            stop_msg.z = 0
            stop_msg.rz = 0
            self.thrust_pub.publish(stop_msg)   
            
            # 保存日志
            self.save_log()
    
    def resume_tuning(self):
        """恢复暂停的调整流程"""
        if not self.is_paused:
            self.get_logger().info("当前没有暂停的调整流程")
            return False
        
        self.get_logger().info("恢复调整流程")
        self.is_paused = False
        self.run_tuning()
        return True
    
    def stop_tuning(self):
        """停止调整流程"""
        self.get_logger().info("停止调整流程")
        self.should_stop = True
        self.save_state()

    def save_log(self):
        """保存调整日志到文件"""
        try:
            # 创建日志数据
            log_data = {
                'timestamp': time.time(),
                'current_motor_pair_index': self.current_motor_pair_index,
                'current_force_index': self.current_force_index,
                'is_paused': self.is_paused,
                'should_stop': self.should_stop,
                'motor_pairs': self.motor_pairs
            }
            
            with open('/home/nvidia/Workspace/Cruise/datas/tuning_log.json', 'w') as f:
                json.dump(log_data, f, indent=2)
            self.get_logger().info("调整日志已保存")
        except Exception as e:
            self.get_logger().error(f"保存调整日志失败: {e}")

def main(args=None):
    """主函数"""
    rclpy.init(args=args)
    node = AutoThrustTuner("uv_auto_thrust_tuner")
    
    # 解析命令行参数
    import argparse
    parser = argparse.ArgumentParser(description='水下机器人推力曲线自动调整系统')
    parser.add_argument('--resume', action='store_true', help='恢复暂停的调整流程')
    parser.add_argument('--stop', action='store_true', help='停止当前的调整流程')
    parser.add_argument('--status', action='store_true', help='显示当前调整状态')
    
    # 解析ROS参数
    args = parser.parse_args(rclpy.utilities.remove_ros_args())
    
    if args.stop:
        # 停止调整流程
        node.stop_tuning()
        node.get_logger().info("已发送停止信号")
    elif args.resume:
        # 恢复调整流程
        if node.resume_tuning():
            node.get_logger().info("调整流程已恢复")
        else:
            node.get_logger().info("没有可恢复的调整流程")
    elif args.status:
        # 显示状态
        node.load_state()
        node.get_logger().info(f"当前状态: 电机对索引={node.current_motor_pair_index}, 推力索引={node.current_force_index}, 暂停={node.is_paused}, 停止={node.should_stop}")
    else:
        # 运行调整流程
        node.run_tuning()
    
    # 关闭节点
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
    
#增加暂停功能，急停功能
#从一个电机的推力倒推整体推力，这样比较灵活
    def save_state(self):
        """保存当前状态到文件"""
        try:
            # 创建状态数据
            state = {
                'current_motor_pair_index': self.current_motor_pair_index,
                'current_force_index': self.current_force_index,
                'test_results': self.test_results,
                'motor_pairs': self.motor_pairs,
                'is_paused': self.is_paused,
                'should_stop': self.should_stop
            }
            
            # 状态文件路径
            state_file = '/home/nvidia/Workspace/Cruise/datas/tuning_state.json'
            backup_file = '/home/nvidia/Workspace/Cruise/datas/tuning_state_backup.json'
            
            # 如果状态文件已存在，创建备份
            import os
            if os.path.exists(state_file):
                try:
                    import shutil
                    shutil.copy2(state_file, backup_file)
                    self.get_logger().debug("状态文件备份已创建")
                except Exception as backup_error:
                    self.get_logger().warn(f"创建状态文件备份失败: {backup_error}")
            
            # 保存状态到文件
            with open(state_file, 'w') as f:
                json.dump(state, f, indent=2)
            self.get_logger().info(f"状态已保存到 {state_file}")
        except Exception as e:
            self.get_logger().error(f"保存状态失败: {e}")
            # 尝试保存到备份文件
            try:
                with open('/home/nvidia/Workspace/Cruise/datas/tuning_state_backup.json', 'w') as f:
                    json.dump(state, f, indent=2)
                self.get_logger().warn("状态已保存到备份文件")
            except Exception as backup_save_error:
                self.get_logger().error(f"保存状态到备份文件也失败了: {backup_save_error}")
    
    def load_state(self):
        """从文件加载状态"""
        state_file = '/home/nvidia/Workspace/Cruise/datas/tuning_state.json'
        backup_file = '/home/nvidia/Workspace/Cruise/datas/tuning_state_backup.json'
        
        # 尝试从主状态文件加载
        state = None
        try:
            with open(state_file, 'r') as f:
                state = json.load(f)
        except FileNotFoundError:
            self.get_logger().info("未找到状态文件，尝试从备份文件加载")
            # 尝试从备份文件加载
            try:
                with open(backup_file, 'r') as f:
                    state = json.load(f)
                self.get_logger().info("从备份文件成功加载状态")
            except FileNotFoundError:
                self.get_logger().info("未找到备份状态文件，从头开始调整")
                return False
            except Exception as backup_error:
                self.get_logger().error(f"从备份文件加载状态失败: {backup_error}")
                return False
        except Exception as e:
            self.get_logger().error(f"从主状态文件加载状态失败: {e}")
            return False
        
        # 验证状态数据
        if not isinstance(state, dict):
            self.get_logger().error("状态数据格式不正确")
            return False
        
        required_keys = ['current_motor_pair_index', 'current_force_index', 'test_results', 'motor_pairs']
        for key in required_keys:
            if key not in state:
                self.get_logger().error(f"状态数据缺少必要字段: {key}")
                return False
        
        # 加载状态
        try:
            self.current_motor_pair_index = state['current_motor_pair_index']
            self.current_force_index = state['current_force_index']
            self.test_results = state['test_results']
            self.motor_pairs = state['motor_pairs']
            
            # 加载可选状态
            self.is_paused = state.get('is_paused', False)
            self.should_stop = state.get('should_stop', False)
            
            self.get_logger().info(f"状态已加载: 电机对索引={self.current_motor_pair_index}, 推力索引={self.current_force_index}, 暂停={self.is_paused}, 停止={self.should_stop}")
            return True
        except Exception as e:
            self.get_logger().error(f"加载状态数据时发生错误: {e}")
            return False