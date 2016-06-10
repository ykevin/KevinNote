#!/usr/bin/python 

def is_odd(n):
    return n % 2 == 1

f = filter(is_odd, [1, 2, 4, 6, 7, 9, 13, 15])
print f


def not_empty(s):
    return s and s.strip()

f = filter(not_empty, ['A', '', 'B', None, 'C', '  '])
print f
