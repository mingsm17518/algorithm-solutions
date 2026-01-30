
n, x = map(int, input().split())
nums = [(int(val), i) for i, val in enumerate(input().split())]
nums.sort()

l = 0
r = n - 1

while l < r:
    cur_sum = nums[l][0] +nums[r][0]
    if cur_sum == x:
        print(nums[l][1]+1, nums[r][1]+1)
        exit()
    elif cur_sum < x:
        l += 1
    else:
        r -= 1
    
print("IMPOSSIBLE")