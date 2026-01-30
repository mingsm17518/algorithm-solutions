
def more_than_b(cnt:map, b:list)->bool:
    for x in range(len(b)):
        if b[x] > cnt.get(x+1, 0):
            return False
    return True

def test(m:int, n:int, a:list, b:list) -> int:
    l = 0
    ans = 1e9
    cnt = {}

    for r, num in enumerate(a):
        cnt[num] = cnt.get(num, 0) + 1
        while l < r and more_than_b(cnt, b):
            ans = min(ans, r-l+1)
            cnt[a[l]] -= 1
            l += 1
    if ans > m:
        ans = 0
    return ans

def main():
    m, n = map(int, input().strip().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    print(test(m, n, a, b))

main()