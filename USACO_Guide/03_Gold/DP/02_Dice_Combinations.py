x = int(input())

dp = [0] * (x + 1)
dp[0] = 1

MOD = 10 ** 9 + 7

for i in range(1, x + 1):
    dp[i] = sum(dp[-6:]) % MOD

print(dp[x])