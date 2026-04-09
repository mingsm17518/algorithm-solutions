s = list(input().strip())

for i in range(len(s)):
    if not s[i].isdigit():
        s[i] = ' '

arr = ''.join(s).split()

ans = max(len(d) for d in arr)
res = ''.join(x for x in arr if len(x) == ans)
print(str(res) + ',' + str(ans))
