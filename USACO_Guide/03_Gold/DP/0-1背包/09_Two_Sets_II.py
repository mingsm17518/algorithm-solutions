import sys

MOD = 10**9 + 7

n = int(input())

sum_elem = n * (n + 1) // 2

if sum_elem % 2 == 1:
	print(0)
	sys.exit()

target = sum_elem // 2

# dp[j] = number of ways to reach sum j
dp = [0] * (target + 1)
dp[0] = 1

for i in range(1, n):
	for j in range(target, i - 1, -1):
		dp[j] = (dp[j] + dp[j - i]) % MOD

print(dp[target])