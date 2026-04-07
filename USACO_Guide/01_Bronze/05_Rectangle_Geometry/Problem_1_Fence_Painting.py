# https://usaco.org/index.php?page=viewproblem2&cpid=567

import sys
sys.stdin = open("paint.in", "r")
sys.stdout = open("paint.out", "w")

a, b = map(int, input().split())
c, d = map(int, input().split())
total = (b - a) + (d - c)
intersection = max(min(b, d) - max(a, c), 0)
union = total - intersection
print(union)
