#!/usr/bin/python 

import os

L = []
for x in range(1, 10):
    L.append(x*x)
print L

print [x*x for x in range(1, 10)]
print [x*x for x in range(1, 10) if x % 2 == 0]
print [m + n for m in 'ABC' for n in 'XYZ']

print [d for d in os.listdir('/')]

d = {'x':'A', 'y':'B', 'z':'C'}

print [k + '=' + v for k, v in d.iteritems()]

L = ['KEVIN', 'ELLIE', 'RIKI']
print [s.lower() for s in L]
