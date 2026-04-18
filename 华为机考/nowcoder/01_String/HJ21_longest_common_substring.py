# HJ21 查找两个字符串a,b中的最长公共子串

a = input()
b = input()

if len(a) > len(b):
    a, b = b, a

res = ''

for i in range(len(a)):
    for j in range(i, len(a)):
        sub = a[i: j + 1]
        if sub in b and len(sub) > len(res):
            res = sub

print(res)