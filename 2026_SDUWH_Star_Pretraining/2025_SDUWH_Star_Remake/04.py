import heapq
from collections import defaultdict

def solve():
    n, k = map(int, input().split())
    a = [0] + [int(input()) for _ in range(n)]

    # 使用堆模拟multiset
    heap = [0]
    cnt = defaultdict(int)
    cnt[0] = 1

    dp = [0] * (n + 2)

    for i in range(1, n + 2):
        if i - k >= 1:
            # 移除 dp[i - k - 1]
            old = dp[i - k - 1]
            cnt[old] -= 1
            if cnt[old] == 0:
                del cnt[old]

        # 获取最小值
        while heap[0] not in cnt:
            heapq.heappop(heap)
        min_val = heap[0]

        if i <= n:
            dp[i] = max(min_val, a[i])
        else:
            dp[i] = min_val

        heapq.heappush(heap, dp[i])
        cnt[dp[i]] += 1

    print(dp[n + 1])

t = int(input())
for _ in range(t):
    solve()
