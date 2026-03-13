import sys
from bisect import bisect

sys.stdin = open("haybales.in", "r")
sys.stdout = open("haybales.out", "w")

N, Q = map(int, input().split())

arr = sorted(list(map(int, input().split())))

for _ in range(Q):
    a, b = map(int, input().split())
    ans = bisect(arr, b) - bisect(arr, a - 1)
    print(ans)