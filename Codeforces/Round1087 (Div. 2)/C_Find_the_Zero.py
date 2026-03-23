t = int(input())

def q(i, j):
    print(f"? {i + 1} {j + 1}")
    ans = int(input())
    return ans

def solve():
    n = int(input())
    for i in range(2, n * 2, 2):
        if q(i, i + 1) == 1:
            print(f"! {i + 1}")
            return
    if q(0, 2) == 1 or q(0, 3) == 1:
        print("! 1")
    else:
        print("! 2")

for _ in range(t):
    solve()

