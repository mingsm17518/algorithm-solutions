# https://codeforces.com/contest/581/problem/D
n = 3
arr = list(map(int, input().split()))

xx = arr[::2]
yy = arr[1::2]
r = 0
sum_xy = 0
mk = [False] * 3

for i in range(n):
    if xx[i] > yy[i]:
        xx[i], yy[i] = yy[i], xx[i]
    r = max(r, yy[i])
    sum_xy += xx[i] * yy[i]

if r * r != sum_xy:
    print(-1)
    exit()

print(r)

H = r

for i in range(n):
    if yy[i] == r:
        H -= xx[i]
        mk[i] = True
        ch = chr(ord('A') + i)
        for _ in range(xx[i]):
            print(ch * r)

for _ in range(H):
    line2print = ""
    for i in range(n):
        if mk[i]:
            continue
        ch = chr(ord('A') + i)
        count = xx[i] if yy[i] == H else yy[i]
        line2print += ch * count
    print(line2print)
