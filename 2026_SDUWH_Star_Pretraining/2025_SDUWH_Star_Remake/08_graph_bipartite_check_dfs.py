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

color = [-1] * n  # -1 表示未染色，0/1 表示染色结果

ans = 0

def dfs(u, col):
    """DFS 染色，返回该连通分量的最小修改次数"""
    stack = [(u, col)]
    res = [0, 0]  # res[0]: 以col=0为基准的修改次数, res[1]: 以col=1为基准的修改次数

    while stack:
        node, col = stack.pop()

        if color[node] == -1:
            color[node] = col
            # 计算以当前col为基准需要修改多少次
            res[0] += col ^ c[node]      # 若最终颜色为0，需要修改多少次
            res[1] += (col ^ 1) ^ c[node] # 若最终颜色为1，需要修改多少次

            for v in adj[node]:
                if color[v] == -1:
                    stack.append((v, col ^ 1))
                elif color[v] == col:
                    print("Impossible")
                    exit()

    return min(res)

for i in range(n):
    if color[i] == -1:
        ans += dfs(i, 0)

print(ans)
