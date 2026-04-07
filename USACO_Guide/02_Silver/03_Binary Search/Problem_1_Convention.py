# https://usaco.org/index.php?page=viewproblem2&cpid=858

import sys
sys.stdin = open("convention.in", "r")
sys.stdout = open("convention.out", "w")

n, m, c = map(int, input().split())
time = [int(x) for x in input().split()]
time.sort()

def first_true(lo, hi, f):
    hi += 1
    while lo < hi:
        mid = lo + (hi - lo) // 2
        if f(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

def can_arrange(x):
    need_bus = 1
    first_ind = 0  # 当前 bus 第一头牛
    cow_up = 1

    for i in range(1, n):
        if time[i] - time[first_ind] > x or cow_up == c:
            first_ind = i
            need_bus += 1
            cow_up = 1
        else:
            cow_up += 1

    return need_bus <= m

ans = first_true(0, time[n - 1] - time[0], can_arrange)
print(ans)