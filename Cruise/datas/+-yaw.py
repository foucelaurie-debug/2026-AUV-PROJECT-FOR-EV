import json
import sys

def modify_setz_params(json_data, value_to_modify):
    try:
        data = json.loads(json_data)
        if "tasks" in data:
            for task in data["tasks"]:
                if "name" in task and task["name"] == "setz" and "params" in task:
                    if "z" in task["params"]:
                        task["params"]["z"] += value_to_modify
        return json.dumps(data, indent=4)
    except json.JSONDecodeError:
        print("Invalid JSON format")
        return None

# 用户定义的数值
user_defined_value = float(input("Enter the value to modify: "))
# 读取JSON文件内容
with open("uv_tasks.json", "r") as file:
    json_content = file.read()

# 调用函数进行修改并获取结果
modified_json = modify_setz_params(json_content, user_defined_value)

# 将修改后的内容写入新文件
if modified_json:
    with open("uv_tasks.json", "w") as file:
        file.write(modified_json)
        print("Modification completed and saved to 'modified_json_file.json'")
