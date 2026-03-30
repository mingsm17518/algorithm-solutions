s = input().strip()
n = len(s)
k = 8
need = (n + k - 1) // k * k
s = s.ljust(need, '0')
for i in range(0, len(s), k):
    print(s[i: i + k])