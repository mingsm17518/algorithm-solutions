t = int(input())

def first_true(lo, hi, check):
    hi += 1
    while lo < hi:
        mid = lo + (hi - lo) // 2
        if check(mid):
            hi = mid
        else:
            lo = mid + 1
    return lo

def can_reach(target):
    farthest = k
    for i in range(1, n + 1):
        if a[i] <= target and i <= farthest:
            farthest = max(farthest, i + k)
    return farthest >= n + 1

for _ in range(t):
    n, k = map(int, input().split())
    a = [0] + [int(x) for x in input().split()]
    result = first_true(min(a), max(a), can_reach)
    print(result)
