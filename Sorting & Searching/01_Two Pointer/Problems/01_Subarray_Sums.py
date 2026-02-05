# https://cses.fi/problemset/task/1660

n, x = map(int, input().split())
arr = list(map(int, input().split()))

l = 0
cur = 0
ans = 0

for r in range(n):
    cur += arr[r]
    while cur > x:
        cur -= arr[l]
        l += 1
    if cur == x:
        ans += 1
        
print(ans)