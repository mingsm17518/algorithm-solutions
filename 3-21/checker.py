import sys

def read_ints(line):
    return list(map(int, line.strip().split()))

def main():
    if len(sys.argv) != 3:
        print("Usage: python checker.py input.txt output.txt")
        return

    with open(sys.argv[1], 'r') as f:
        input_data = f.read().strip().splitlines()
    with open(sys.argv[2], 'r') as f:
        output_data = f.read().strip().splitlines()

    # ===== 读取输入 =====
    ptr = 0
    q = int(input_data[ptr])
    ptr += 1
    S_list = []
    for _ in range(q):
        S_list.append(int(input_data[ptr]))
        ptr += 1

    # ===== 读取输出 =====
    ptr = 0
    n, m = map(int, output_data[ptr].split())
    ptr += 1

    # 检查尺寸
    if not (1 <= n <= 200 and 1 <= m <= 200 and n * m <= 200):
        print("WA: invalid matrix size")
        return

    # 读取矩阵
    mat = []
    for i in range(n):
        row = read_ints(output_data[ptr])
        ptr += 1
        if len(row) != m:
            print("WA: wrong column count")
            return
        for x in row:
            if x < 0 or x > 2**63 - 1:
                print("WA: value out of range")
                return
        mat.append(row)

    # 检查路径数量
    if len(output_data) - ptr != q:
        print("WA: wrong number of paths")
        return

    # ===== 检查每个查询 =====
    for qi in range(q):
        path = output_data[ptr].strip()
        ptr += 1

        x, y = 0, 0  # (0,0) 对应 (1,1)
        visited = set()
        visited.add((x, y))

        total = mat[x][y]

        for c in path:
            if c not in "UDLR":
                print(f"WA: invalid char in path {qi}")
                return

            if c == 'U':
                x -= 1
            elif c == 'D':
                x += 1
            elif c == 'L':
                y -= 1
            elif c == 'R':
                y += 1

            # 越界
            if not (0 <= x < n and 0 <= y < m):
                print(f"WA: out of bounds in query {qi}")
                return

            # 重复访问
            if (x, y) in visited:
                print(f"WA: revisiting cell in query {qi}")
                return

            visited.add((x, y))
            total += mat[x][y]

        # 是否到终点
        if (x, y) != (n-1, m-1):
            print(f"WA: not ending at target in query {qi}")
            return

        # 和是否正确
        if total != S_list[qi]:
            print(f"WA: wrong sum in query {qi}, got {total}, expect {S_list[qi]}")
            return

    print("AC: all tests passed!")

if __name__ == "__main__":
    main()