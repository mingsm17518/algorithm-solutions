# https://usaco.org/index.php?page=viewproblem2&cpid=567

import sys
sys.stdin = open("paint.in", "r")
sys.stdout = open("paint.out", "w")

a, b = map(int, input().split())
c, d = map(int, input().split())

if a > c:
    a, c = c, a
    b, d = d, b

if b < c:
    ans = b - a + d - c
else:
    if d < b:
        ans = b - a
    else:
        ans = d - a

print(ans)