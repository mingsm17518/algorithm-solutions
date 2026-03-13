# https://usaco.org/index.php?page=viewproblem2&cpid=783

import sys
sys.stdin = open("billboard.in", "r")
sys.stdout = open("billboard.out", "w")

x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())

tl = y4 >= y2 and x3 <= x1
tr = y4 >= y2 and x4 >= x2
br = x4 >= x2 and y4 <= y1
bl = x3 <= x1 and y3 <= y1

if bl and tr:
    print(0)
    exit()

left = max(x1, x3)
bottom = max(y1, y3)
right = min(x2, x4)
top = min(y2, y4)

s1 = (x2 - x1) * (y2 - y1)
inter = (right - left) * (top - bottom)

if tl + tr + br + bl == 2:
    print(s1 - inter)

else:
    print(s1)