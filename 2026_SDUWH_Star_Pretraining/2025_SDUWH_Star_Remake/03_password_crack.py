def idx_to_password(idx):
    res = []
    for _ in range(m):
        res.append(s[idx % k])
        idx //= k
    return ''.join(reversed(res))
  
n, m = map(int, input().split())
s = input().strip()

k = len(s)
total = k ** m
lenth_for_machine = total // n
remainder = total % n
a = 0
for i in range(n):
    len_i = lenth_for_machine
    if i < remainder:
        len_i += 1
    b = a + len_i
    print(idx_to_password(a), idx_to_password(b - 1))
    a = b
