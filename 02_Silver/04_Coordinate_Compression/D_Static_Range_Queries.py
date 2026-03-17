# https://codeforces.com/gym/102951/problem/D

n, q = map(int, input().split())
diff_dict = dict()
coord_set = {-1}
queries = []

for _ in range(n):
    left, right, add_val = map(int, input().split())
    coord_set.add(left)
    coord_set.add(right)
    diff_dict[left] = diff_dict.get(left, 0) + add_val
    diff_dict[right] = diff_dict.get(right, 0) - add_val

for _ in range(q):
    left, right = map(int, input().split())
    coord_set.add(left)
    coord_set.add(right)
    queries.append((left, right))

coord_set = sorted(coord_set)
idx_dict = {coord_set[i]: i for i in range(len(coord_set))}

cur_value = 0
prefix_sum = [0]

for i in range(1, len(coord_set)):
    segment_len = coord_set[i] - coord_set[i - 1]
    segment_sum = cur_value * segment_len
    prefix_sum.append(prefix_sum[-1] + segment_sum)
    cur_value += diff_dict.get(coord_set[i], 0)


for (l, r) in queries:
        left_idx = idx_dict[l]
        right_idx = idx_dict[r]
        ans = prefix_sum[right_idx] - prefix_sum[left_idx]
        print(ans)