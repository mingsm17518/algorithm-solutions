INF = 10 ** 18
n, x = map(int, input().split())
arr = list(map(int, input().split()))

dp = [INF] * (x + 1)
dp[0] = 0

for coin in arr:
    for i in range(coin, x + 1):
        dp[i] = min(dp[i], dp[i - coin] + 1)
    
print(dp[x] if dp[x] != INF else -1)