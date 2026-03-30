n, w, q_num = map(int, input().split())
s = [int(x) for x in input().split()]
q = [(s[i], s[i] + w - 1, i) for i in range(q_num)]
q.sort(key=lambda x: x[1])

record_num = int(input())
record = []
for _ in range(record_num):
    num, time = map(int, input().split())
    record.append((time, num))

record.sort()

l = 0
r = 0
ans = [0] * q_num
cnt = 0
appear = {}

for start, end, i in q:
    while r < record_num and record[r][0] <= end:
        id = record[r][1]
        appear[id] = appear.get(id, 0) + 1
        if appear[id] == 1:
            cnt += 1
        r += 1

    while l < record_num and record[l][0] < start:
        id = record[l][1]
        appear[id] -= 1
        if appear[id] == 0:
            cnt -= 1
        l += 1
    ans[i] = cnt

print(' '.join(map(str, ans)))
