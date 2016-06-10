#!/usr/bin/python 

import math

def move(x, y, setp, angle=0):
    nx = x + setp*math.cos(angle)
    ny = y - setp*math.sin(angle)

    return nx, ny

x, y = move(100, 100, 60, math.pi / 6)
r  = move(100, 100, 60, math.pi / 6)

print x, y
print r

