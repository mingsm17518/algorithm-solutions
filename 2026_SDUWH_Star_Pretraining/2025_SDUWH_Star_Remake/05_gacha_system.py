n, x, y, z = map(int, input().split())

s = ["E"] * n

pos = 179
while z > 0 and pos < n:
    if s[pos] == "E":
        s[pos] = "D"
        z -= 1
    pos += 180

pos = 89
while pos < n:
    if s[pos] == "E":
        if y > 0:
            s[pos] = "C"
            y -= 1
        elif z > 0:
            s[pos] = "D"
            z -= 1
    pos += 90

pos = 9
while pos < n:
    if s[pos] == "E":
        if x > 0:
            s[pos] = "B"
            x -= 1
        elif y > 0:
            s[pos] = "C"
            y -= 1
        elif z > 0:
            s[pos] = "D"
            z -= 1
    pos += 10

for i in range(n):
    if s[i] == "E":
        if z > 0:
            s[i] = "D"
            z -= 1
        elif y > 0:
            s[i] = "C"
            y -= 1
        elif x > 0:
            s[i] = "B"
            x -= 1
        else:
            s[i] = "A"

print("".join(s))
