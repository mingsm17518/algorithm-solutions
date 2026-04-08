n = int(input())
money = list(map(int, input().split()))

max_sum = sum(money)
dp = [False] * (max_sum + 1)
dp[0] = True

for coin in money:
	for j in range(max_sum, coin - 1, -1):
		if dp[j - coin]:
			dp[j] = True

res = [i for i in range(1, max_sum + 1) if dp[i]]

print(len(res))
print(*res)