n, target = map(int, input().split())
arr = [int(x) for x in input().split()]

INF = 1e6

dp = [INF] * (target + 1)

for coin in arr:
	for i in range(target - coin + 1):
		dp[i + coin] = min(dp[i + coin], dp[i] + 1)


print(dp[target] if dp[target] != INF else -1)