#!/usr/bin/python 

f = sorted([3, 2, 10, 100, 1, 5])

print f


def reverse_cmp(x, y):
    if x > y:
        return -1
    if x < y:
        return 1
    return 0
f = sorted([3, 2, 100, 50, 30, 100], reverse_cmp)
print f
