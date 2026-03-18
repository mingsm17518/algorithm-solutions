import sys
l, r, ans = 1, 7, 0
for i in range(3):
    mid = (l + r) // 2
    print(f"? {mid}")
    sys.stdout.flush()
    a = input()
    if a == '<':
        l = mid + 1
    elif a == '>':
        r = mid - 1
    else:
        ans = mid
        break
print(f"! {ans}")
sys.stdout.flush()