# HJ22 字符串通配符
"""
规则：
- '*' 匹配 0 个或多个数字或字母
- '?' 匹配 1 个数字或字母
- 字母不区分大小写
- 其他字符精确匹配
"""

def is_alnum(c):
    """判断是否是字母或数字"""
    return c.isalnum()


def wildcard_match(s, p):
    """判断通配符 s 是否能匹配目标字符串 p"""
    m, n = len(s), len(p)

    # dp[i][j] = 通配符前 i 个字符能否匹配目标前 j 个字符
    dp = [[False] * (n + 1) for _ in range(m + 1)]

    # 边界：空匹配空
    dp[0][0] = True

    # 边界：通配符前缀全是 * 才能匹配空目标
    for i in range(1, m + 1):
        if s[i - 1] == '*':
            dp[i][0] = dp[i - 1][0]
        else:
            break  # 遇到非 *，后面都是 False

    # 状态转移
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            sc = s[i - 1]
            pc = p[j - 1]

            if sc == '*':
                # * 可以匹配 0 个或多个字母数字
                # dp[i-1][j]: * 匹配 0 个
                # dp[i][j-1]: * 匹配 1+ 个（当前字符必须是字母数字）
                dp[i][j] = dp[i - 1][j]
                if is_alnum(pc):
                    dp[i][j] = dp[i][j] or dp[i][j - 1]

            elif sc == '?':
                # ? 匹配 1 个字母数字
                if is_alnum(pc):
                    dp[i][j] = dp[i - 1][j - 1]

            elif sc.isalpha():
                # 字母不区分大小写
                if sc.lower() == pc.lower():
                    dp[i][j] = dp[i - 1][j - 1]

            else:
                # 其他字符精确匹配
                if sc == pc:
                    dp[i][j] = dp[i - 1][j - 1]

    return dp[m][n]


def main():
    s = input().strip()
    p = input().strip()

    result = wildcard_match(s, p)
    print("true" if result else "false")


if __name__ == "__main__":
    main()

# 测试
# z -> zz -> false
# Z* -> zz -> true
# ?* -> zz -> true
# **Z -> 0QZz -> true
# ??** -> zz -> true
# HH?* -> HH##1 -> false
