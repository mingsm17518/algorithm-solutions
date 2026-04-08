s = input().strip()

from collections import Counter

c = Counter(s)

res = []

for key, val in c.items():
    if val == 1:
        res.append(key)

for ch in s:
    if ch in res:
        print(ch)
        exit()

print(-1)