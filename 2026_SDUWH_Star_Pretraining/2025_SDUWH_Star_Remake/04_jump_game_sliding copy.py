"""
跳跃过桥问题 - 滑动窗口+单调队列解法

核心思路：
- 使用单调队列维护窗口 [i-k, i-1] 内的最小代价
- 队列按代价单调递增，队首始终是窗口内的最小值
"""

from collections import deque


def solve_one(n, k, a):
    """
    单调队列求解
    队列存储 (位置, 代价)，按代价单调递增
    队首 q[0] = 窗口内代价最小的元素
    """
    q = deque()
    q.append((0, 0))  # (位置, 代价)，起点代价为 0

    cur_cost = 0  # 当前计算出的代价

    for i in range(1, n + 2):
        # 滑动窗口：移除无法跳到位置 i 的位置
        # 位置 i 只能从 [i-k, i-1] 跳过来
        while q and q[0][0] < i - k:
            q.popleft()

        if q:
            # 队首是窗口内代价最小的
            min_cost = q[0][1]
            # 到达 i 的代价 = max(前一步的最小代价, i位置的价值)
            cur_cost = max(min_cost, a[i])

            # 移除队列中代价更大的元素（它们永远不会是最优的）
            while q and q[-1][1] >= cur_cost:
                q.pop()
            q.append((i, cur_cost))

    return cur_cost

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = [0] + list(map(int, input().split())) + [0]  # 添加终点，值为0
    print(solve_one(n, k, a))
