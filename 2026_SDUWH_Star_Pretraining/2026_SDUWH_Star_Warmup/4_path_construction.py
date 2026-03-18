import sys
input = sys.stdin.readline

q = int(input())
S_list = [int(input()) for _ in range(q)]
n = max(S_list).bit_length()

print(n + 1, 3)
for i in range(n):
    print(0, 1 << i, 0)
print("0 0 0")

for S in S_list:
    path = []
    flag = 1
    for i in range(n):
        if (S >> i) & 1:
            path.extend(['RR' if flag else 'LL', 'D'])
            flag ^= 1
        else:
            path.append('D')
    if flag:
        path.append('RR')
    print(''.join(path))
