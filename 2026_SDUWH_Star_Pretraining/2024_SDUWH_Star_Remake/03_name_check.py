n = int(input())
arr = set(input() for _ in range(n))
m = int(input())
c = set()
for _ in range(m):
    s = input().strip()
    if s in arr:
        if s not in c:
            print("OK")
            c.add(s)
        else:
            print("REPEAT")
    else:
        print("WRONG")