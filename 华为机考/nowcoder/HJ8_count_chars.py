s = input().strip()

alpha = 0
space = s.count(' ')
digit = 0

for c in s:
    if c.isdigit():
        digit += 1
    elif c.isalpha():
        alpha += 1

other = len(s) - alpha - space - digit

print(alpha)
print(space)
print(digit)
print(other)
