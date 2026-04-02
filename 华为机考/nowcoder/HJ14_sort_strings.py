# HJ14 字符串排序

n = int(input())
arr = [input().strip() for _ in range(n)]

arr.sort()
for s in arr:
    print(s)

