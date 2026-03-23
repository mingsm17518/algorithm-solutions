class Fenwick:
    """树状数组 (Fenwick Tree / Binary Indexed Tree)"""

    def __init__(self, n: int = 0):
        self.n = n
        self.a = [0] * n

    def init(self, n: int):
        self.n = n
        self.a = [0] * n

    def add(self, x: int, v):
        """在位置 x 加上 v (0-indexed)"""
        i = x + 1
        while i <= self.n:
            self.a[i - 1] = self.a[i - 1] + v
            i += i & -i

    def sum(self, x: int):
        """求前缀和 [0, x] (0-indexed, 包含 x)"""
        ans = 0
        i = x + 1
        while i > 0:
            ans = ans + self.a[i - 1]
            i -= i & -i
        return ans

    def range_sum(self, l: int, r: int):
        """求区间和 [l, r] (0-indexed, 包含两端)"""
        if l == 0:
            return self.sum(r)
        return self.sum(r) - self.sum(l - 1)

    def select(self, k):
        """找到满足 sum(i) <= k 的最大 i"""
        x = 0
        cur = 0
        i = 1 << (self.n.bit_length() - 1)
        while i:
            if x + i <= self.n and cur + self.a[x + i - 1] <= k:
                x += i
                cur = cur + self.a[x - 1]
            i >>= 1
        return x
