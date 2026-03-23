from collections import Counter

n = int(input())
arr = [int(x) for x in input().split()]

count = Counter(arr)
a = count[1]
b = count[2]
if a <= b:
    ans = a
else:
    ans = b
    a -= b
    ans += a // 3

print(ans)