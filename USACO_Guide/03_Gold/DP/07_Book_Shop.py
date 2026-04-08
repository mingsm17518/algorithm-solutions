n, x = map(int, input().split())
cost = [int(x) for x in input().split()]
pages = [int(x) for x in input().split()]

dp = [0] * (x + 1)

for i in range(n):
    for j in range(x, cost[i] - 1, -1):
        dp[j] = max(dp[j], dp[j - cost[i]] + pages[i])

print(dp[x])