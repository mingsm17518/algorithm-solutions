import sys
sys.setrecursionlimit(10**6)

n, m = map(int, input().split())
node = list(map(int, input().split()))

adj = [[] for _ in range(n)]
for _ in range(n):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    adj[u].append(v)
    adj[v].append(u)

vis = [-1] * n

def dfs(u, c):
    vis[u] = c
    cnt = (vis[u] != node[u])  # 当前颜色与node[u]不匹配的个数
    total = 1
    for v in adj[u]:
        if vis[v] == c:
            return False, 0, 0
        if vis[v] == -1:
            ok, cc, tot = dfs(v, 1 ^ c)
            if not ok:
                return False, 0, 0
            cnt += cc
            total += tot
    return True, cnt, total

ans = 0
for u in range(n):
    if vis[u] == -1:
        ok, c, tot = dfs(u, 0)
        if not ok:
            print("Impossible")
            exit()
        ans += min(c, tot - c)

print(ans)
