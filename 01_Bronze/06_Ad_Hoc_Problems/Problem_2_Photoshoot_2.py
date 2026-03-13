# https://usaco.org/index.php?page=viewproblem2&cpid=1204

n = int(input())
arr = [int(x) for x in input().split()]
target = [int(x) for x in input().split()]
moved = [False] * (n + 1)
ans = 0
j = 0
for i in range(n):
    while j < n and moved[arr[j]]:
        j += 1
    if j >= n:
        break
    if target[i] == arr[j]:
        j += 1
    else:
        ans += 1
        moved[target[i]] = True

print(ans)