s = list(set(input().strip()))
ans = 0
for c in s:
    x = ord(c)
    if x <= 127:
        ans += 1
print(ans)
