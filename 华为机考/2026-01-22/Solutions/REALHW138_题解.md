# 小红的岁晚可可塔

## 题目描述

- n 层蛋糕，每层有甜度值 a[i]
- 求连续子数组的最大和

## 解法：Kadane 算法（最大子数组和）

### 核心思路

遍历数组，用两个变量：
- `cur`: 当前以第 i 个元素结尾的最大子数组和
- `ans`: 遍历过程中的最大子数组和

状态转移：
- `cur = max(a[i], cur + a[i])`：要么从新开始，要么继续之前的
- 如果 `cur < 0`，重置为 0（因为负数和只会让后续更小）

### 代码实现

```python
n = int(input())
a = [int(x) for x in input().split()]

cur = 0
ans = float('-inf')  # 注意：必须用负无穷，不能用 -1e-10
for i in range(n):
    cur += a[i]
    ans = max(ans, cur)
    if cur < 0:
        cur = 0

print(ans)
```

### 复杂度分析

| 操作 | 复杂度 |
|------|--------|
| 时间 | O(n) |
| 空间 | O(1) |

### 图解示例

```
a = [2, -4, 3, -1, 2, -4, 3]

i=0: cur=2, ans=2, cur>=0
i=1: cur=-2, ans=2, cur<0 → cur=0
i=2: cur=3, ans=3, cur>=0
i=3: cur=2, ans=3, cur>=0
i=4: cur=4, ans=4, cur>=0  ← 最大
i=5: cur=0, ans=4, cur<0 → cur=0
i=6: cur=3, ans=4, cur>=0

输出: 4
```
