#!/usr/bin/python 

g = (x * x for x in range(10))
for n in g:
    print n

def fib(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b
        a, b = b, a + b
        n = n + 1

for n in fib(10):
    print n
