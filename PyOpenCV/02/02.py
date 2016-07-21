#!/usr/bin/python 

import numpy as np
import cv2

# -1 cv2.IMREAD_COLOR
#  0 cv2.IMREAD_GRAYSCALE
#  1 cv2.IMREAD_UNCHANGED
img = cv2.imread('empire.jpg', 0)
cv2.imshow('image', img)
k = cv2.waitKey(0)&0xff
if k == 27:
    cv2.destroyAllWindows()
elif k == ord('s'):
    cv2.imwrite('test.png', img)
    cv2.destroyAllWindows()
