t = int(input())

for _ in range(t):
    n, c, k = map(int, input().split())
    arr = [int(x) for x in input().split()]
    arr.sort()
    for x in arr:
        if c >= x:
            cnt = min(k, c - x)
            c += x + cnt
            k -= cnt
    print(c)