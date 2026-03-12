# https://usaco.org/index.php?page=viewproblem2&cpid=689

import sys
sys.stdin = open("cowtip.in", "r")
sys.stdout = open("cowtip.out", "w")

def flip(x, y):
    pass

n = int(input())
cows = []

for i in range(n):
    row = list(map(int, input().strip()))
    cows.append(row)

min_flips = 0

x = n - 1
y = n - 1

while x >= 0 and y >= 0:
    if cows[x][y] == 1:
        min_flips += 1
        for i in range(x + 1):
            for j in range(y + 1):
                cows[i][j] ^= 1
    if y > 0:
        y -= 1
    else:
        x -= 1
        y = n - 1

print(min_flips)
    