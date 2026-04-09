s = input().strip()

def expand(l, r):
    while l >= 0 and r < len(s) and s[l] == s[r]:
        l -= 1
        r += 1
    return s[l + 1:r]

res = ""
for i in range(len(s)):
    # 奇数长度
    res = max(res, expand(i, i), key=len)
    # 偶数长度
    res = max(res, expand(i, i + 1), key=len)

print(res)
