# HJ17 字符串字符匹配

s = set(input())
t = set(input())

flag = s <= t
print("true") if flag else print("false")