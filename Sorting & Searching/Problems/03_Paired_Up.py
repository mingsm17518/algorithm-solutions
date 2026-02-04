import sys

# sys.stdin = open("pairup.in", "r")
# sys.stdout = open("pairup.out", "w")

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
    sub_num = min(cows[l][1], cows[r][1])
    