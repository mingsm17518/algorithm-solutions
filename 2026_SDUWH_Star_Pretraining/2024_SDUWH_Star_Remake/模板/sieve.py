minp = []
primes = []

def sieve(n: int):
    """埃拉托斯特尼筛法 - 计算 minp 和 primes"""
    global minp, primes
    minp = [0] * (n + 1)
    primes = []

    for i in range(2, n + 1):
        if minp[i] == 0:
            minp[i] = i
            primes.append(i)

        for p in primes:
            if i * p > n:
                break
            minp[i * p] = p
            if p == minp[i]:
                break
