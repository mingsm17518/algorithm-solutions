MOD = 10**9 + 7

n = int(input())

dp = [1]

for i in range(n):
    total = sum(dp[-6:])
    dp.append(total % MOD)

print(dp[-1])