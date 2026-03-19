n, m = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# dp[i][j]: 考虑A前i个和B前j个的最长友好数组长度
dp = [[0] * (m + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, m + 1):
        # 如果 A[i-1] 和 B[j-1] 可以配对
        # 需要满足: B[j-1] - A[i-1] = dp[i-1][j-1]
        # 即: A[i-1] + dp[i-1][j-1] == B[j-1]
        if A[i - 1] + dp[i - 1][j - 1] == B[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

print(dp[n][m])
