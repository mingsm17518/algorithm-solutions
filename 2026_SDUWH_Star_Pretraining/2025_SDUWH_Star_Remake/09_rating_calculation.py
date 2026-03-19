n = int(input())
arr = [int(x) for x in input().split()]
y = 0
for p in arr:
    x = y
    y = x + (p - x) // 4
    if (p - x) % 4 >= 2:
        y += 1
    print(y, end=' ')