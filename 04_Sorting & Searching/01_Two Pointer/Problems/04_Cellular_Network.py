# https://codeforces.com/contest/702/problem/C

n, m = map(int, input().split())

city = list(map(int, input().split()))
tower = list(map(int, input().split()))

j = 0

ans = 0

for i in range(n):

    while j + 1 < m and abs(city[i] - tower[j+1]) <= abs(city[i] - tower[j]):
        j += 1
    
    ans = max(ans, abs(city[i] - tower[j]))

print(ans)
