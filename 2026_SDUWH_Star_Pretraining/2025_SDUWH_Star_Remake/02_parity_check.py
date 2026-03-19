n = int(input())

arr = [int(x) for x in input().split()]

sorted_arr = sorted(arr)
flag = True

for i in range(n):
    if sorted_arr[i] % 2 != arr[i] % 2:
        print("NO")
        exit()

print("YES")
