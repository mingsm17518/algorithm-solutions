import sys

for line in sys.stdin:
    list1 = map(int, line.strip().split())
    print(sum(list1))
