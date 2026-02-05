import sys

sys.stdin = open("pairup.in", "r")
sys.stdout = open("pairup.out", "w")

n = int(input())

cows = []
for _ in range(n):
    num, time = map(int, input().split())
    cows.append([time, num])

cows.sort()
l = 0
r = n - 1
ans = 0

while l <= r:
    sub = min(cows[l][1], cows[r][1])
    ans = max(ans, cows[l][0] + cows[r][0])
    if l == r:
        sub /= 2
    cows[l][1] -= sub
    cows[r][1] -= sub
    if cows[l][1] == 0:
        l += 1
    if cows[r][1] == 0:
        r -= 1
print(ans)