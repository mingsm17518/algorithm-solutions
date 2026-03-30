# HJ8 统计字符

s = input().strip()

ch = 0
space = 0
num = 0


for c in s:
    x = ord(c)
    if (x >= 65 and x <= 90) or (x >= 97 and x <= 122):
        ch += 1
    elif c == ' ':
        space += 1
    elif x >= 48 and x <= 57:
        num += 1

print(ch)
print(space)
print(num)
print(len(s) - ch - space - num)
