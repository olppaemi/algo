# https://onlinejudge.org/external/103/10360.pdf

import sys
input = sys.stdin.readline


def solution(strength, rats):
    killed = [[0] * 1025 for _ in range(1025)]

    for x, y, population in rats:
        xl, xr = max(0, x - strength), min(x + strength, 1024)
        yl, yr = max(0, y - strength), min(y + strength, 1024)
        for i in range(xl, xr + 1):
            for j in range(yl, yr + 1):
                killed[i][j] += population

    x, y, max_killed = 0, 0, 0
    for i in range(1025):
        for j in range(1025):
            if killed[i][j] > max_killed:
                x, y, max_killed = i, j, killed[i][j]
    return x, y, max_killed


test_case = int(input())
for i in range(test_case):
    strength = ''
    while not strength:
        strength = input().rstrip()

    strength = int(strength)
    n = int(input())
    rats = []
    for _ in range(n):
        rats.append(list(map(int, input().split())))
    x, y, p = solution(strength, rats)
    print(x, y, p)
