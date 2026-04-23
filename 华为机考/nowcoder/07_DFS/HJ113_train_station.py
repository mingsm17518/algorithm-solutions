n = int(input())
nums = [int(x) for x in input().split()]

ans = []

def dfs(wait, stack, out):
    if not wait and not stack:
        ans.append(' '.join(map(str, out)))
    if wait:
        dfs(wait[1:], stack + [wait[0]], out)
    if stack:
        dfs(wait, stack[:-1], out + [stack[-1]])

dfs(nums, [], [])
    
for x in sorted(ans):
    print(x)
