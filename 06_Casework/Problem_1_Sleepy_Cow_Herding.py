import sys
sys.stdin = open("herding.in", "r")
sys.stdout = open("herding.out", "w")

a, b, c = map(int, input().split())

if c == a + 2:
    min_ans = 0
elif c == b + 2 or b == a + 2:
    min_ans = 1
else:
    min_ans = 2

max_dis = max(b - a, c - b)
max_ans = max_dis - 1
print(min_ans)
print(max_ans)