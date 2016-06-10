#!/usr/bin/python 

def power(x, n):
    s = 1
    while n > 0:
        n = n - 1
        s = s*x

    return s

s = power(5, 3)
print s

def enroll(name, grade, age=6, city='foshan'):
    print 'name: ', name
    print 'grade:', grade
    print 'age: ', age
    print 'city: ', city

enroll('kevin', 'A', 22, 'bejing')
enroll('Riki', 'B')

def calc(*numbers):
    sum = 0;
    for n in numbers:
        sum = sum + n*n
    return sum

print calc(1, 2)
print calc()

num = [1, 2, 3]
print calc(*num)

def person(name, age, **kw):
    print 'name : ', name, 'age : ', age, 'other : ', kw
print person("kevin", 22)
print person('riki', 1, city = 'foshan')


def func(a, b, c=0, *args, **kw):
    print 'a= ', a, 'b= ', b, 'c= ', c, 'args= ', args, 'kw=', kw
func(1, 2)
func(1, 2, c=3)
func(1, 2, 3, 'a', 'b')
func(1, 2, 3, 'a', 'b', x=99)
