n = int(input())

dp = [1]

MOD = 10 ** 9 + 7

for i in range(n):
    total = sum(dp[-6:]) % MOD
    dp.append(total)

print(dp[-1])