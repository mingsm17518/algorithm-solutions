t = int(input())
from itertools import permutations

for tt in range(t):
    n = int(input())
    s = [int(x) for x in input().split()]
    d = [int(x) for x in input().split()]
    f = [int(x) for x in input().split()]
    ans = 0
    arr = []
    for p in permutations(range(n)):
        time = 0
        score = 0
        for i in p:
            time += d[i]
            score += round(max(s[i] - 50 * f[i] - time * s[i] // 250, 0.3 * s[i]))
        if ans < score:
            ans = score
            arr = p
    res = ''
    for x in arr:
        res += chr(ord('A') + x)
    print(ans, res)
        
