def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    dp = [0] * n
    dp[0] = a[0]
    
    for i in range(n - 1):
        # 情况 1: 直接从前一个位置转移
        dp[i + 1] = dp[i] + a[i + 1] - 1
        
        # 情况 2: 如果 i > 0，尝试从 i-1 位置跳跃转移
        if i > 0:
            val = max(0, a[i + 1] - i - 1)
            dp[i + 1] = min(dp[i + 1], dp[i - 1] + a[i] + val)
    
    print(dp[n - 1])


t = int(input())
while t > 0:
    solve()
    t -= 1
