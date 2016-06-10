#!/usr/bin/python 

def fact(n):
    if n == 1:
        return 1;
    return n*fact(n - 1)

print fact(5)
print fact(100)

l = []
n = 1
while n <= 99:
    l.append(n)
    n = n + 2

print l
