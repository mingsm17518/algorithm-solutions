# https://usaco.org/index.php?page=viewproblem2&cpid=663

import sys
sys.stdin = open("square.in", "r")
sys.stdout = open("square.out", "w")


r1 = tuple(map(int, input().split()))
r2 = tuple(map(int, input().split()))

left = min(r1[0], r2[0])
bottom = min(r1[1], r2[1])
right = max(r1[2], r2[2])
top = max(r1[3], r2[3])

a = max(right - left, top - bottom)

print(a * a)