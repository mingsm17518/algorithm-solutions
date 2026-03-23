n = int(input())
arr = [int(x) for x in input().split()]

def prime_factors(n):
    factors = set()
    d = 2
    while d * d <= n:
        while n % d == 0:
            factors.add(d)
            n //= d
        d += 1
    if n > 1:
        factors.add(n)
    return factors

ans = 0

dp = {}

for i in range(n):
    if arr[i] == 1:
        continue
    fac = prime_factors(arr[i])
    if fac:
        cur = max(dp.get(x, 0) for x in fac) + 1
    else:
        cur = 1
    for x in fac:
        dp[x] = cur
    ans = max(ans, cur)

print(ans)
