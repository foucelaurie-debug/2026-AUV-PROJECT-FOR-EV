from uv_vision import stereocam
import cv2
import numpy as np


front_sc = stereocam.StereoCamera()
front_sc.cal_parameters_init("/home/macabaka/Workspace/Rosws/datas/stereo_calib.npz")
front_sc.rectification_init()

print(front_sc.map1_left, front_sc.map2_left)

image = cv2.imread("imgs/img_2.jpg")

cv2.imshow("image", image)

cv2.waitKey(0)

cv2.destroyAllWindows()

img_l, img_r = front_sc.get_halfimg(image)

img_l, img_r = front_sc.rectifyImage(img_l, img_r)

depth_map = front_sc.getdepth(img_l, img_r)

depth,depth_image = front_sc.depth2img(depth_map)

cv2.imshow("depth_map", depth_image)

cv2.waitKey(0)

cv2.destroyAllWindows()


