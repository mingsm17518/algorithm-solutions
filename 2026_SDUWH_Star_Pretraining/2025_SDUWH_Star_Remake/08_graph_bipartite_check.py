from collections import deque
import sys
sys.setrecursionlimit(10**6)   

n, m = map(int, input().split())
c = [int(x) for x in input().split()]

adj = [[] for _ in range(n)]
for i in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append(v)
    adj[v].append(u)

visited = [-1] * n

ans = 0

for i in range(n):
    if visited[i] != -1:
        continue
    q = deque([i])
    visited[i] = 0
    res = [0, 0]
    while q:
        u = q.popleft()
        res[0] += visited[u] ^ c[u]
        res[1] += (visited[u] ^ 1) ^ c[u]

        for v in adj[u]:
            if visited[v] == -1:
                q.append(v)
                visited[v] = visited[u] ^ 1
            elif visited[v] == visited[u]:
                print("Impossible")
                exit()

    ans += min(res)              
        
print(ans)