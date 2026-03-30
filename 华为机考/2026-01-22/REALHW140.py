"""
小红制作蛋糕 - 带门槛的01背包问题
"""

n, w, e, k = map(int, input().split())
x = list(map(int, input().split()))  # 门槛
y = list(map(int, input().split()))  # 甜度增益
z = list(map(int, input().split()))  # 体力消耗

# 按门槛排序，确保制作顺序合理
cakes = sorted(zip(x, y, z))

# dp[j][t] = 制作j个蛋糕，消耗t体力，能达到的最大甜度
# 初始化为-1表示不可达
dp = [[-1] * (e + 1) for _ in range(k + 1)]
dp[0][0] = w  # 初始甜度

for x_i, y_i, z_i in cakes:
    # 倒序遍历（01背包）
    for j in range(k - 1, -1, -1):
        for t in range(e - z_i, -1, -1):
            if dp[j][t] >= x_i:  # 满足门槛条件
                new_t = t + z_i
                new_sweet = dp[j][t] + y_i
                dp[j + 1][new_t] = max(dp[j + 1][new_t], new_sweet)

# 找最大甜度和最少蛋糕数
max_sweet = w
min_cakes = 0
for j in range(k + 1):
    for t in range(e + 1):
        if dp[j][t] > max_sweet:
            max_sweet = dp[j][t]
            min_cakes = j
        elif dp[j][t] == max_sweet and dp[j][t] != -1 and j < min_cakes:
            min_cakes = j

print(max_sweet, min_cakes)
