t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    if y == 0:
        if x % 3 == 0:
            print("YES")
        else:
            print("NO")
    elif y > 0:
        if x >= 2 * y and (x - 2 * y) % 3 == 0:
            print("YES")
        else:
            print("NO")
    else:
        if x >= -4 * y and (x + 4 * y) % 3 == 0:
            print("YES")
        else:
            print("NO")
