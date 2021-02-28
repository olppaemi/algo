# https://onlinejudge.org/external/7/787.pdf

import sys


def solution(a):
    cur_max_product = a[0]
    prev_max_product = a[0]
    prev_min_product = a[0]
    ans = a[0]

    for i in range(1, len(a)):
        cur_max_product = max(
            prev_max_product*a[i], prev_min_product*a[i], a[i])
        cur_min_product = min(
            prev_max_product*a[i], prev_min_product*a[i], a[i])
        ans = max(ans, cur_max_product)
        prev_max_product = cur_max_product
        prev_min_product = cur_min_product

    return ans


for line in sys.stdin.readlines():
    arr = list(map(int, line.split()))[:-1]
    print(solution(arr))
