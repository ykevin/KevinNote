#!/usr/bin/python 

x = abs(-10)
print x

def add(x, y , f):
    return f(x) + f(y)

f = abs
print add(-5, 6 , f)
