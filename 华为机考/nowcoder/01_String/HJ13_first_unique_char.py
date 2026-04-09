from collections import Counter

s = input().strip()
cnt = Counter(s)

for ch in s:
    if cnt[ch] == 1:
        print(ch)
        exit()

print(-1)