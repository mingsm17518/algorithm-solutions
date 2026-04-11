line = input().split()
n = int(line[0])
arr = line[1: n + 1]
x = line[n + 1]
x_sort = sorted(x)
k = int(line[-1])
res = []

for s in arr:
    if sorted(s) == x_sort and s != x:
        res.append(s)

res.sort()
print(len(res))
if k <= len(res):
    print(res[k - 1])
