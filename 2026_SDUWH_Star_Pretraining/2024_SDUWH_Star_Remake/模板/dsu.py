class DSU:
    """并查集 (Disjoint Set Union)"""

    def __init__(self, n: int = 0):
        self.init(n)

    def init(self, n: int):
        self.n = n
        self.cnt = n
        self.f = list(range(n))
        self.siz = [1] * n

    def find(self, x: int) -> int:
        while x != self.f[x]:
            self.f[x] = self.f[self.f[x]]
            x = self.f[x]
        return x

    def same(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)

    def merge(self, x: int, y: int) -> bool:
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return False
        if self.siz[x] < self.siz[y]:
            x, y = y, x
        self.f[y] = x
        self.siz[x] += self.siz[y]
        self.cnt -= 1
        return True

    def size(self, x: int) -> int:
        return self.siz[self.find(x)]

    def count(self) -> int:
        return self.cnt
