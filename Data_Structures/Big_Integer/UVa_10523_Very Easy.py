# https://onlinejudge.org/external/105/10523.pdf

import sys


def solution(n, a):
    answer = 0
    for i in range(1, n + 1):
        answer += i * (a ** i)
    return answer


for line in sys.stdin.readlines():
    n, a = map(int, line.split())
    print(solution(n, a))
