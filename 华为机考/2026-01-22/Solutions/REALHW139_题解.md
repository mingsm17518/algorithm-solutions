# 小红的慕斯模具统计

## 题目描述

https://www.nowcoder.com/practice/c016abeeac86418db4ae97319de04af5

- N 种模具（编号 0~N-1）
- M 条使用记录：(模具编号, 使用时间)
- K 个查询：给定起始时间 S，求区间 [S, S+X-1] 内不同模具的数量

## 解法：离线查询 + 双指针 + 哈希表

### 核心思路

将 K 个查询按**结束时间排序**，用**滑动窗口**维护当前区间内的模具种类数。

### 算法步骤

1. 将 M 条记录按时间排序
2. 将 K 个查询按结束时间排序
3. 用双指针维护滑动窗口 [L, R]
4. 右指针扩展时加入记录，左指针收缩时移除记录
5. 用哈希表统计当前窗口内每种模具的出现次数

### 代码实现

```python
# 输入
n, w, q_num = map(int, input().split())  # n: 模具数, w: 跨度, q_num: 查询数
s = [int(x) for x in input().split()]    # 起始时间列表

# 构建查询: (起始, 结束, 索引)
queries = [(s[i], s[i] + w - 1, i) for i in range(q_num)]
queries.sort(key=lambda x: x[1])

# 读取记录: (时间, 模具ID)
record_num = int(input())
records = []
for _ in range(record_num):
    id, t = map(int, input().split())
    records.append((t, id))
records.sort()

# 双指针滑动窗口
ans = [0] * q_num
l = r = 0
cnt = 0
appear = {}  # 模具ID -> 出现次数

for start, end, idx in queries:
    # 右指针右移：加入 [start, end] 区间内的记录
    while r < record_num and records[r][0] <= end:
        id = records[r][1]
        appear[id] = appear.get(id, 0) + 1
        if appear[id] == 1:
            cnt += 1
        r += 1

    # 左指针右移：移除 start 之前的记录
    while l < record_num and records[l][0] < start:
        id = records[l][1]
        appear[id] -= 1
        if appear[id] == 0:
            cnt -= 1
        l += 1

    ans[idx] = cnt

print(' '.join(map(str, ans)))
```

### 复杂度分析

| 操作 | 复杂度 |
|------|--------|
| 排序 | O(M log M + K log K) |
| 滑动窗口 | O(M + K) |
| 总时间 | O((M+K) log (M+K)) |
| 空间 | O(M) |

### 图解示例

```
记录 (时间, 模具): [(2,1), (3,2), (4,2), (5,3)]

查询1: [3,4] → 窗口内只有模具2 → ans=1
查询2: [4,5] → 窗口内有模具2,3 → ans=2
```
