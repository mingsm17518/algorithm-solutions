s = input().strip()

from collections import Counter

cnt = Counter(s)

small = min(cnt.values())

for c in s:
    if cnt[c] != small:
        print(c,end='')