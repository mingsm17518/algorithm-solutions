import sys

sys.stdin = open("haybales.in", "r")
sys.stdout = open("haybales.out", "w")

N, Q = map(int, input().split())

arr = sorted(list(map(int, input().split())))

def at_most(arr, x: int) -> int:
    lo = 0
    hi = len(arr)
    while lo < hi:
        mid = (lo + hi) // 2
        if arr[mid] <= x:
            lo = mid + 1
        else:
            hi = mid
    return lo

for _ in range(Q):
    a, b = map(int, input().split())
    ans = at_most(arr, b) - at_most(arr, a - 1)
    print(ans)