n = int(input())
arr = [int(x) for x in input().split()]

dp = [float("inf") for _ in range(n)]

dp[0] = 0

for i in range(1, n):
    if i >= 1:
        dp[i] = min(dp[i], dp[i - 1] + abs(arr[i] - arr[i - 1]))
    if i >= 2:
        dp[i] = min(dp[i], dp[i - 2] + abs(arr[i] - arr[i - 2]))

print(dp[-1])
