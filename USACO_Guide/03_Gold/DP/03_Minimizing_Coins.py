n, target = map(int, input().split())
arr = [int(x) for x in input().split()]

INF = 10**7

dp = [INF] * (target + 1)
dp[0] = 0

for coin in arr:
	for i in range(coin, target + 1):
		dp[i] = min(dp[i], dp[i - coin] + 1)


print(dp[target] if dp[target] != INF else -1)