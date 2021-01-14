# https://onlinejudge.org/external/109/10943.pdf

import sys

memo = [[0] * (101) for _ in range(101)]


def search(n, k):
    global memo
    if k == 1:
        return 1
    if not memo[n][k]:
        for i in range(n + 1):
            memo[n][k] += search(n - i, k - 1)
    return memo[n][k] % 1_000_000


inp = iter(sys.stdin.readlines())
while True:
    n, k = map(int, next(inp).split())
    if not n and not k:
        break
    print(search(n, k))
