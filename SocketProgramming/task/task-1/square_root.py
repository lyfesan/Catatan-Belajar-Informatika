import math

n = int(input())
n_sqrt = math.isqrt(n)

if n_sqrt ** 2 == n:
    print(n_sqrt)
else:
    print("Not a perfect square")