import sys

data = sys.stdin.read().split()
n = int(data[0])
k = int(data[1])
coins = list(map(int, data[2:]))

can = [[False] * (k + 1) for _ in range(k + 1)]
can[0][0] = True

for c in coins:
    for x in range(k - c, -1, -1):
        for y in range(k - c - x, -1, -1):
            if can[x][y]:
                can[x + c][y] = True
                can[x][y + c] = True

result = [x for x in range(k + 1) if can[x][k - x]]

print(len(result))
print(*result)