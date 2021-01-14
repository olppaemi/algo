from bisect import bisect_left
import sys
input = sys.stdin.readline


def solution(n, a):
    L = [None] * n
    lis = 0
    for i in range(n):
        pos = bisect_left(L, a[i], 0, lis)
        L[pos] = a[i]
        if pos + 1 > lis:
            lis = pos + 1
    print(L)
    return lis


n = int(input())
a = list(map(int, input().split()))
print(solution(n, a))
