n = int(input())
a = [int(x) for x in input().split()]

cur = 0
ans = float('-inf')
for i in range(n):
    cur += a[i]
    ans = max(ans, cur)
    if cur < 0:
        cur = 0

print(ans)