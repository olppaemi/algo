# https://onlinejudge.org/external/118/11849.pdf

import sys
input = sys.stdin.readline

while True:
    N, M = map(int, input().split())

    if not N and not M:
        break

    jack, jill = set(), set()
    for _ in range(N):
        jack.add(int(input()))

    for _ in range(M):
        jill.add(int(input()))

    print(len(jack & jill))
