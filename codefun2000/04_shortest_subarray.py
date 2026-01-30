def solution(n, target, nums):
    ans = 1e9
    left = 0
    cur_sum = 0
    for right in range(n):
        cur_sum += nums[right]
        while cur_sum >= target:
            ans = min(ans, right - left + 1)
            cur_sum -= nums[left]
            left += 1
    if ans == 1e9:
        ans = 0
    return ans
        

def main():
    n, target = map(int, input().strip().split())
    nums = list(map(int, input().strip().split()))
    ans = solution(n, target, nums)
    print(ans)

main()
