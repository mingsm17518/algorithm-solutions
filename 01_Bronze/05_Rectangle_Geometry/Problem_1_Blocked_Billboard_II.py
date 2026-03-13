# https://usaco.org/index.php?page=viewproblem2&cpid=783

import sys
sys.stdin = open("billboard.in", "r")
sys.stdout = open("billboard.out", "w")

lawnmower = tuple(map(int, input().split()))
feed = tuple(map(int, input().split()))

left = max(lawnmower[0], feed[0])
bottom = max(lawnmower[1], feed[1])
right = min(lawnmower[2], feed[2])
top = min(lawnmower[3], feed[3])

s1 = (lawnmower[2] - lawnmower[0]) * (lawnmower[3] - lawnmower[1]) 

a = right - left
b = top - bottom
inter = a * b

if a == feed[2] - feed[0] or b == feed[3] - feed[1]:
    print(s1 - inter)
else:
    print(s1)
