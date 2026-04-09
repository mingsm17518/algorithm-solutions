s1 = input().strip()
s2 = input().strip()

def fun(s, flag):
    res = []
    for ch in s:
        cur = ord(ch)
        if ch.isalpha():
            if ch.islower():
                base = ord('a')
                new = ord('A')
            else:
                base = ord('A')
                new = ord('a')
            cur = (cur - base + flag) % 26 + new
            
        else:
            cur = (cur - ord('0') + flag) % 10 + ord('0')
        res.append(chr(cur))
    print(''.join(res))

fun(s1, 1)
fun(s2, -1)