a,b = map(int, input().split())

import math
g = math.gcd(a, b)

def count(n):
    cnt = 0
    d = 2
    while d * d <= n:
        while n % d == 0:
            cnt += 1
            n //= d
        d += 1
    if n > 1:
        cnt += 1
    return cnt

ans = count(b // g) + count(a // g)

print(ans)