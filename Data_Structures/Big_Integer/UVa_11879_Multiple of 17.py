# https://onlinejudge.org/external/118/11879.pdf

import sys
input = sys.stdin.readline


while True:
    n = int(input())
    if n == 0:
        break
    if n % 17 == 0:
        print(1)
    else:
        print(0)
