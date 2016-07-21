#!/usr/bin/python 

import numpy as np
import cv2
from matplotlib import pyplot as plt

# -1 cv2.IMREAD_COLOR
#  0 cv2.IMREAD_GRAYSCALE
#  1 cv2.IMREAD_UNCHANGED
img = cv2.imread('empire.jpg', -1)
#img = cv2.imread('empire.jpg', 0)
plt.imshow(img, cmap = 'gray', interpolation = 'bicubic')
#plt.imshow(img)
plt.xticks([]), plt.yticks([])
plt.show()
