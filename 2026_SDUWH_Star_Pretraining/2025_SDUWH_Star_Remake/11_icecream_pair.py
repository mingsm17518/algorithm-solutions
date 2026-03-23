n = int(input())
a = [int(x) for x in input().split()]


total = sum(a)

if total % 2 != 0:
    print("NO")
    exit()

max_count = max(a)
if max_count > total // 2:
    print("NO")
    exit()

print("YES")
