# https://onlinejudge.org/external/6/674.pdf

import sys

coins = (1, 5, 10, 25, 50)
ways = [1] + [0] * 7490


def solution():
    for c in coins:
        for i in range(c, 7490):
            ways[i] += ways[i - c]


solution()
for money in sys.stdin:
    print(ways[int(money)])
