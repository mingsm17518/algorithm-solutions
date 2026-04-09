s = input().strip()

from collections import Counter

cnt = Counter(s)

min_cnt = min(cnt.values())
for ch in s:
    if cnt[ch] != min_cnt:
        print(ch, end='')