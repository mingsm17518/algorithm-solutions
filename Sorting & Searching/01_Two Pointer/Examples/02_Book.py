# https://codeforces.com/contest/279/problem/B

# 寻找连续子数组：子数组的和小于t，且最长

n, t = map(int, input().split())
timeNeed = list(map(int, input().split()))

l = 0
sum_time = 0
ans = 0

for r in range(n):
    sum_time += timeNeed[r]
    while sum_time > t and l <= r:
        sum_time -= timeNeed[l]
        l += 1
    ans = max(ans, r - l + 1)

print(ans)