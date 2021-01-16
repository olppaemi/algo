# https://onlinejudge.org/external/100/10020.pdf

import sys
sys.stdin = open('input.txt')
sys.stdout = open('output.txt', 'w')


def solution(m, coords):
    LEFT, RIGHT = 0, 1
    coords.sort()
    answer = []

    n = len(coords)
    i, covered, next_covered = 0, 0, 0

    while i < n:
        pos = -1
        while i < n and coords[i][LEFT] <= covered:
            if coords[i][RIGHT] > next_covered:
                next_covered = coords[i][RIGHT]
                pos = i
            i += 1
        if pos < 0:
            break

        answer.append(pos)
        covered = next_covered
        if covered >= m:
            break
        i = pos + 1

    if covered < m:
        print(0)
    else:
        print(len(answer))
        for pos in answer:
            print(f"{coords[pos][LEFT]} {coords[pos][RIGHT]}")


inp = iter(sys.stdin.readlines())
test_case = int(next(inp))
for count in range(test_case):
    m = ''
    while not m:
        m = next(inp).rstrip()
    m = int(m)
    coords = []

    while True:
        l, r = map(int, next(inp).split())
        if not l and not r:
            break
        coords.append((l, r))

    solution(m, coords)
    if count != test_case - 1:
        print()
