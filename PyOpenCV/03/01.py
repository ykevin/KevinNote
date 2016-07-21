#!/usr/bin/python 
import numpy as np
import cv2 

#cap = cv2.VideoCapture("/home/ubuntu/catkin_ws/src/rbx1/rbx1_vision/videos/hide2.mp4")
cap = cv2.VideoCapture(0)

while(True):
    ret, frame = cap.read()

    if(ret):
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        cv2.imshow('frame', gray)
        if cv2.waitKey(1) & 0xff == ord('q'):
            break
    else:
        print "read failed!"

cap.release()
cv2.destroyAllWindows()
