tt = int(input())
for _ in range(tt):
    n = int(input())
    s = input().strip()
    if n == 2 and s[0] != s[1]:
        print(-1)
        continue
    s2 = s + s
    pos = {}
    ans = n - 1
    for i, c in enumerate(s2):
        if c in pos:
            ans = min(ans, i - pos[c] - 1)
        pos[c] = i
    if ans == n - 1:
        print(-1)
    else:
        print(ans)
