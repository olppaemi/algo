# https://onlinejudge.org/external/7/750.pdf

def solution(x, y):
    row = [0] * 8
    line_counter = 1

    def place(r, c):
        for prev in range(c):  # check previously placed queens
            if row[prev] == r or abs(row[prev] - r) == abs(prev - c):
                return False
        return True

    def backtrack(c):
        nonlocal line_counter
        if c == 8 and row[y] == x:
            print(f"{line_counter:2}      {row[0] + 1}", end="")
            for i in range(1, 8):
                print(f" {row[i] + 1}", end="")
            print()
            line_counter += 1
        for r in range(8):
            if c == y and r != x:
                continue
            if place(r, c):
                row[c] = r
                backtrack(c + 1)

    print("SOLN       COLUMN")
    print(" #      1 2 3 4 5 6 7 8")
    print()
    backtrack(0)


test_case = int(input())
for count in range(test_case):
    if count:
        print()
    l = ''
    while not l:
        l = input()
    x, y = map(int, l.split())
    solution(x - 1, y - 1)
