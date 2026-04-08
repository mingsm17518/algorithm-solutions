s = input().strip()
# print(int(s,16))
s = s[:1:-1]
dic = {'A':10,'B':11,'C':12,'D':13,'E':14,'F':15}
ans = 0
for i in range(len(s)):
    if s[i] not in dic:
        w = int(s[i])
    else:
        w = dic[s[i]]
    ans += 16 ** i * w
print(ans)