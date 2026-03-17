# https://usaco.org/index.php?page=viewproblem2&cpid=690

import sys
import heapq

n, t = map(int, input().split())
d = []
for _ in range(n):
    d.append(int(input()))

def fun(k):
    # 使用最小堆模拟演出过程
    heap = []
    # 前k只cow直接上舞台
    for i in range(min(k, n)):
        heapq.heappush(heap, d[i])

    # 剩余的cow依次上场
    for i in range(k, n):
        # 等待最早结束的cow
        earliest = heapq.heappop(heap)
        # 下一只cow在earliest时间后开始
        heapq.heappush(heap, earliest + d[i])

    # 返回最后一只cow结束的时间（堆中的最大值）
    return max(heap)


def first_true(lo, hi, f):
    # 找最小的k使得 f(k) 为真
    while lo < hi:
        mid = lo + (hi - lo) // 2
        if f(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

print(first_true(1, n, lambda k: fun(k) <= t))