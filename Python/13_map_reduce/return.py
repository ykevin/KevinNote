#!/usr/bin/python 

def lazy_sum(*args):
    def sum():
        au = 0
        for n in args:
            au = au + n
        return au
    return sum

f = lazy_sum(1, 2, 3, 4, 5, 6)
print f()    

def count():
    fs = []
    for i in range(1, 4):
        def f(j):
            def g():
                return j*j
            return g
        fs.append(f(i))
        return fs

f1 = count()
print f1()
