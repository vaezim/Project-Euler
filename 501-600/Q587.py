from math import sqrt, asin, atan, sin, pi


def x(n):
    return (1 + 1.0/n - sqrt(2.0/n)) / (1 + 1.0/(n**2))
def y(n):
    return x(n) / n
def d(n):
    return sqrt((x(n)**2) + (y(n)**2))
def angle(n):
    return atan(1.0/n)
def triangle_area(n):
    return d(n) * sin(angle(n)) / 2.0
def d2(n):
    return sqrt((x(n)-1)**2 + y(n)**2)
def sector_area(n):
    return asin(d2(n)/2.0) - sin(2.0 * asin(d2(n)/2.0))/2.0
def a(n):
    return triangle_area(n) - sector_area(n)

A = 1 - pi/4.0
n = 1
while a(n) > 0.001 * A:
    n += 1

print("Answer =", n)