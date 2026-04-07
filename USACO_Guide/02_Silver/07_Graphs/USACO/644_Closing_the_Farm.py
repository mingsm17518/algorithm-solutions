import sys

sys.stdin = open("closing.in", "r")
sys.stdout = open("closing.out", "w")

n, m = map(int, input().split())
adj = [[] for _ in range(n)]
visited = [False] * n
closed = [False] * n
order = []

for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append(v)
    adj[v].append(u)

for _ in range(n):
    order.append(int(input())-1)

nodes = 0

def dfs(node):
    global nodes
    if visited[node] or closed[node]:
        return 
    nodes += 1
    visited[node] = True
    for u in adj[node]:
        if not visited[u]:
            dfs(u)

dfs(0)
print("YES") if nodes == n else print("NO")

for i in range(n-1):
    visited = [False] * n
    nodes = 0
    closed[order[i]] = True
    dfs(order[i+1])
    print("YES") if nodes == n-i-1 else print("NO")

