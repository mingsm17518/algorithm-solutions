# https://usaco.org/index.php?page=viewproblem2&cpid=759

import sys
sys.stdin = open("billboard.in", "r")
sys.stdout = open("billboard.out", "w")

def count_s(x1, y1, x2, y2):
    s = (y2 - y1) * (x2 - x1)
    return s

def inter_area(n1, n2):
    left = max(n1[0], n2[0])
    bottom = max(n1[1], n2[1])
    right = min(n1[2], n2[2])
    top = min(n1[3], n2[3])

    if left >= right or bottom >= top:
        return 0
    return (right - left) * (top - bottom)

board1 = tuple(map(int, input().split()))
board2 = tuple(map(int, input().split()))
truck = tuple(map(int, input().split()))

s1 = count_s(board1[0], board1[1], board1[2], board1[3])
s2 = count_s(board2[0], board2[1], board2[2], board2[3])

sum_of_s = s1 + s2

intersetion = inter_area(board1, truck) + inter_area(board2, truck)

ans = sum_of_s - intersetion

print(ans)



