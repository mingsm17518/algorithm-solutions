def get_divisors(n: int):
    """返回 1 到 n 所有数的约数列表"""
    divs = [[] for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(i, n + 1, i):
            divs[j].append(i)
    return divs
