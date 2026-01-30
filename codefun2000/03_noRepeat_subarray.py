import sys

# [无重复字符的最长子串](https://codefun2000.com/p/P3787)
# [leetcode-link](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)

def solution(str: str) -> int:
    if not str:
        return 0
    
    last = {}
    left = 0
    ans = 0
    
    for right, ch in enumerate(str):
        if ch in last and last[ch] >= left:
            left = last[ch] + 1
        last[ch] = right
        ans = max(ans, right - left + 1)
        
    return ans

def main():
    str = sys.stdin.readline().strip()
    ans = solution(str)
    print(ans)

main()