n, x = map(int, input().split())
arr = [int(x) for x in input().split()]

arr.sort()
use_time = 0
ans = 0
for i in range(n):
    use_time += arr[i]
    if use_time > x:
        break
    ans += 1

print(ans)