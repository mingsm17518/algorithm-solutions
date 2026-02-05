n, x = map(int, input().split())
a = list(map(int, input().split()))

p = [(a[i], i+1) for i in range(n)]

p.sort()

for i in range(n):
    l = 0
    r = n - 1
    while l < r:
        target = x - p[i][0]
        if l != i and r != i and p[l][0] + p[r][0] == target:
            print(p[l][1], p[r][1], p[i][1])
            exit()
        elif p[l][0] + p[r][0] < target:
            l += 1
        else:
            r -= 1

print("IMPOSSIBLE")