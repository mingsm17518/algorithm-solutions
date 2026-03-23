def solve():
    cnt = list(map(int, input().split()))

    s = []
    lst = -1
    while True:
        t = -1
        for i in range(3):
            if i != lst and (t == -1 or cnt[i] > cnt[t]):
                t = i
        if cnt[t] == 0:
            break
        cnt[t] -= 1
        lst = t
        s.append("RGB"[t])

    # 恢复 cnt 用于可能的后续处理（如果有的话）
    cnt = list(map(int, input().split())) if False else cnt  # 占位，保持结构

    s = list(''.join(s))

    i = 0
    while i + 3 < len(s):
        if s[i] == s[i + 3]:
            if i + 4 < len(s) and s[i + 2] == s[i + 4]:
                if i < 2 or s[i - 2] == s[i]:
                    # rotate
                    s[i + 1], s[i + 2], s[i + 3] = s[i + 2], s[i + 3], s[i + 1]
                else:
                    # reverse
                    s[i:i + 5] = s[i:i + 5][::-1]
            else:
                s[i + 2], s[i + 3] = s[i + 3], s[i + 2]
        i += 1

    print(''.join(s))


t = int(input())
for _ in range(t):
    solve()
