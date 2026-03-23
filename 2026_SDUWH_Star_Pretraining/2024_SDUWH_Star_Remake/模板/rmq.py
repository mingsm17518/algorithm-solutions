class RMQ:
    """区间最值查询 (Range Minimum Query)"""

    def __init__(self, v=None):
        if v is not None:
            self.init(v)

    def init(self, v):
        """初始化数组 v"""
        import math
        n = len(v)
        self.n = n
        self.B = 64

        self.pre = v[:]
        self.suf = v[:]
        self.ini = v[:]

        if n == 0:
            return

        M = (n - 1) // self.B + 1
        lg = math.log2(M)

        self.a = [[None] * M for _ in range(int(lg) + 1)]

        # 预处理每个块内的最小值
        for i in range(M):
            self.a[0][i] = v[i * self.B]
            for j in range(1, self.B):
                if i * self.B + j < n:
                    self.a[0][i] = min(self.a[0][i], v[i * self.B + j])

        # 前缀最小值
        for i in range(1, n):
            if i % self.B:
                self.pre[i] = min(self.pre[i], self.pre[i - 1])

        # 后缀最小值
        for i in range(n - 2, -1, -1):
            if i % self.B != self.B - 1:
                self.suf[i] = min(self.suf[i], self.suf[i + 1])

        # Sparse Table
        j = 1
        while (1 << j) <= M:
            for i in range(M - (1 << j) + 1):
                self.a[j][i] = min(self.a[j - 1][i], self.a[j - 1][i + (1 << (j - 1))])
            j += 1

    def query(self, l: int, r: int):
        """查询区间 [l, r] 的最小值"""
        import math
        if l > r:
            return float('inf')
        if l // self.B != (r - 1) // self.B:
            ans = min(self.suf[l], self.pre[r - 1])
            l = l // self.B + 1
            r = r // self.B
            if l < r:
                k = int(math.log2(r - l))
                ans = min(ans, self.a[k][l], self.a[k][r - (1 << k)])
            return ans
        else:
            x = self.B * (l // self.B)
            # 简化的同块查询
            return min(self.ini[l:r + 1])
