n, k = map(int, input().split())
arr = [int(x) for x in input().split()]
arr.sort()

def last_true(lo, hi, f):
    lo -= 1
    while lo < hi:
        mid = lo + (hi - lo + 1) // 2
        if f(mid):
            lo = mid
        else:
            hi = mid - 1
    return lo

def med_reachable(x):
    ops = 0
    for i in range((n - 1) // 2, n):
        ops += max(0, x - arr[i])
    return ops <= k


ans = last_true(1, int(2e9), med_reachable)

print(ans)