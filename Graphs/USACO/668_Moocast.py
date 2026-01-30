import sys
sys.stdin = open("moocast.in", "r")
sys.stdout = open("moocast.out", "w")

n = int(input())

x = [0 for _ in range(n)]
y = [0 for _ in range(n)]
power = [0 for _ in range(n)]

for i in range(n):
    x[i], y[i], power[i] = map(int, input().split())

adj = [[] for _ in range(n)]
for i in range(n):
    for j in range(n):
        dist = (x[i] - x[j]) ** 2 + (y[i] - y[j]) ** 2
        if dist <= (power[i] **2):
            adj[i].append(j)

def dfs(node):
    global visited
    visited[node] = True
    reached = 1
    for i in adj[node]:
        if not visited[i]:
            reached += dfs(i)
    return reached

ans = 0
for i in range(n):
    visited = [False for _ in range(n)]
    ans = max(ans, dfs(i))

print(ans)