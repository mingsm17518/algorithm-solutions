MOD = 10**9 + 7

n, x = map(int, input().split())
coins = list(map(int, input().split()))

dp = [0] * (x + 1)
dp[0] = 1

for i in range(x + 1):
    for c in coins:
        if i - c >= 0:
            dp[i] = (dp[i - c] + dp[i]) % MOD

print(dp[x])