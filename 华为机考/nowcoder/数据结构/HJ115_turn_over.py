n, m = map(int, input().split())
temp = [input() for _ in range(n)]

from collections import Counter

s = []
for j in range(m):
    pattern = ''.join(temp[i][j] for i in range(n))
    s.append(pattern)

c = Counter(s)
ans = max(c.values())
print(ans)
