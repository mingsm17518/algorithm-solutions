n, q = map(int, input().split())
s = input().strip()

pref = [[0] * (n + 1) for _ in range(26)]

for i in range(n):
    for c in range(26):
        pref[c][i + 1] = pref[c][i]
    pref[ord(s[i]) - 97][i + 1] += 1

for _ in range(q):
    flag = False
    l, r = map(int, input().split())
    for c in range(26):
        if pref[c][r] - pref[c][l - 1] == 1:
            flag = True
            break
    if flag:
        print("YES")
    else:
        print("NO")
