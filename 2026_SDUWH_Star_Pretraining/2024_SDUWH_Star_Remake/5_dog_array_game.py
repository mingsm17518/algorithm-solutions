n = int(input())
arr = [int(x) for x in input().split()]
arr.sort(reverse=True)

s = sum(arr)
avg = s // n
rem = s % n

ans = 0
for i in range(n):
    if rem > 0:
        rem -= 1
        ans += abs(arr[i] - (avg + 1)) 
    else:
        ans += abs(arr[i] - avg)
ans = ans // 2

print(ans)