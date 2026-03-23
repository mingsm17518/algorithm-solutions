t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    for i in range(n):
        l = 0
        r = 0
        for j in range(i + 1, n):
            if a[j] < a[i]:
                l += 1
            if a[j] > a[i]:
                r += 1
        print(max(l, r), end=' ')
    print()