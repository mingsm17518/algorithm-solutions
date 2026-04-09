s = input().strip()
n = len(s)
k = 8
new_len = (n + k - 1) // k * k
s = s.ljust(new_len, '0')
for i in range(0, new_len, k):
    print(s[i: i + k])