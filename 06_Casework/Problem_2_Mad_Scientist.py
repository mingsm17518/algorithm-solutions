import sys

sys.stdin = open("breedflip.in", "r")
sys.stdout = open("breedflip.out", "w")

n = int(input())

a = input()
b = input()
flag = True
ans = 0
for i in range(n):
    if flag == True:
        if a[i] != b[i]:
            ans += 1
            flag = False
    else:
        if a[i] == b[i]:
            flag = True
print(ans)