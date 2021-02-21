# https://onlinejudge.org/external/7/713.pdf

import sys
input = sys.stdin.readline

tc = int(input())
for _ in range(tc):
    a, b = input().split()
    print(int(str(int(a[::-1]) + int(b[::-1]))[::-1]))
