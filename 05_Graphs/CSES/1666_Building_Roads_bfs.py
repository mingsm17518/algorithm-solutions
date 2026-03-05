from collections import deque

n, m = map(int, input().split())

adj = [[] for _ in range(n)]
visited = [False] * n

for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append(v)
    adj[v].append(u)

c = 0

connect = []
    
for i in range(n):
    if not visited[i]:
        c += 1
        connect.append(i)
        q = deque([i])
        while q:
            node = q.popleft()
            visited[node] = True
            for v in adj[node]:
                if not visited[v]:
                    q.append(v)

print(c-1)
for i in range(c-1):
    print(connect[i]+1, connect[i+1]+1)
    

