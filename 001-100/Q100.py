########################################
#
# Quadratic Diophantine equation solver:
# https://www.alpertron.com.ar/QUAD.HTM
#
# b + r = N
# We need to solve 2b^2 - 2b - N^2 + N = 0
# b0 = 1, n0 = 1
# bn+1 = 3*⁢bn + 2*Nn - 2
# Nn+1 = 4*⁢bn + 3*Nn - 3
#
########################################

b = 1
N = 1

while N < 10**12:
    _b = 3*b + 2*N - 2
    N = 4*b + 3*N - 3
    b = _b

print(f"b = {b} | N = {N}")