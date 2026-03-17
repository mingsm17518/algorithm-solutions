# https://usaco.org/index.php?page=viewproblem2&cpid=690

import sys
import heapq

sys.stdin = open("cowdance.in", "r")
sys.stdout = open("cowdance.out", "w")

n, t = map(int, input().split())
d = []
for _ in range(n):
    d.append(int(input()))

def fun(k):
    show = d[:k]
    heapq.heapify(show)
    for i in range(k, n):
        earliest = heapq.heappop(show)
        heapq.heappush(show, earliest + d[i])
    return max(show)

def first_true(lo, hi, f):
    hi += 1
    while lo < hi:
        mid = lo + (hi - lo) // 2
        if f(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

print(first_true(1, n, lambda k: fun(k) <= t))