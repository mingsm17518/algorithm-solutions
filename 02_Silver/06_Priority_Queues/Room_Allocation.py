# https://cses.fi/problemset/task/1164

import heapq

n = int(input())
timetable = []
for i in range(n):
    a, b = map(int, input().split())
    timetable.append((a, b, i))
timetable.sort(key=lambda x: x[0])

heap = []
ans = 0
results = [-1] * n

for a, b, i in timetable:
    if heap and a > heap[0][0]:
        r = heap[0][1]
        heapq.heapreplace(heap, (b, r))
    else:
        ans += 1
        r = ans
        heapq.heappush(heap, (b, r))
    results[i] = r

print(ans)
print(*results)
