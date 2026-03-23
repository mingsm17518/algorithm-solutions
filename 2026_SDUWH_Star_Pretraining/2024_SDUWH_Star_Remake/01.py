n, m = map(int, input().split())

arr = [int(x) for x in input().split()]

if n % 2 == 1:
    mid = n // 2 + 1
    if mid in arr or (mid - 1 in arr and mid + 1 in arr):
        print("Goldye")
    else:
        print("Xiaozhu Hahaha")
else:
    mid = n // 2
    if mid in arr and mid + 1 in arr:
        print("Goldye")
    else:
        print("Xiaozhu Hahaha")