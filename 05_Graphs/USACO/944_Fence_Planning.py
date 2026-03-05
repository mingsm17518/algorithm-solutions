import sys
sys.setrecursionlimit(10**7)

sys.stdin = open("fenceplan.in", "r")
sys.stdout = open("fenceplan.out", "w")

n, m = map(int, input().split())
x = []
y = []
for i in range(n):
    xi, yi = map(int, input().split())
    x.append(xi)
    y.append(yi)

adj = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append(v)
    adj[v].append(u)

visited = [False for _ in range(n)]

connected = [[] for _ in range(n)]

ans = 1e9

def dfs(node):
    global idx
    visited[node] = True
    connected[idx].append(node)
    for i in adj[node]:
        if not visited[i]:
            dfs(i)

idx = 0

for i in range(n):
    if not visited[i]:
        dfs(i)
        idx += 1

for net in connected:
    if net:
        max_x = max(x[u] for u in net)
        min_x = min(x[u] for u in net)
        max_y = max(y[u] for u in net)
        min_y = min(y[u] for u in net)
        ans = min(ans, max_x-min_x+max_y-min_y)


print(ans*2)