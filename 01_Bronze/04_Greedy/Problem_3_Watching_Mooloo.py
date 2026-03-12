import sys


n, k = map(int, input().split())
arr = [int(x) for x in input().split()]
ans = k + 1

for i in range(1, n):
    if arr[i] - arr[i - 1] <= k:
        ans += arr[i] - arr[i-1]
    else:
        ans += k + 1

print(ans)