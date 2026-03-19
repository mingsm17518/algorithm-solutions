from collections import deque

t = int(input())

def solve_one(n, k, a):
    q = deque()
    q.append((0, 0))
    cost = 0

    for i in range(1, n + 2):
        while q and q[0][0] < i - k:
            q.popleft()
        if q:
            cost = max(q[0][1], a[i])
            while q and q[-1][1] >= cost:
                q.pop()
            q.append((i, cost))
    return cost

    
for _ in range(t):
    n, k = map(int, input().split())
    a = [0] + list(map(int, input().split())) + [0]
    print(solve_one(n, k, a))