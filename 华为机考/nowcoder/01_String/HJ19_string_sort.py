# HJ19 字符串排序

s = input()

arr = [ch for ch in s if ch.isalpha()]

arr.sort(key=str.lower)

res = []
cur = 0
for ch in s:
    if ch.isalpha():
        res.append(arr[cur])
        cur += 1
    else:
        res.append(ch)

print(''.join(res))