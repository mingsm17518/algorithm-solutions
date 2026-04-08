s = input().strip()

temp = ""

for c in s:
    if c.isdigit():
        temp = temp + c
    else:
        temp = temp + ' '

arr = temp.split()

ans = 0
res = ""
for d in arr:
    ans = max(ans, len(d))
for d in arr:
    if len(d) == ans:
        res = res + d

print(str(res) + ',' + str(ans))
