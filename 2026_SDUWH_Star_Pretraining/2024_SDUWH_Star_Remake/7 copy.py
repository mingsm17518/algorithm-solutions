n = int(input())
arr = [int(input()) for _ in range(n)]

s = set()
l = 0
ans = 0

for r in range(n):
    while arr[r] in s:
        s.remove(arr[l])
        l += 1
    s.add(arr[r])
    ans = max(ans, r - l + 1)

print(ans)
