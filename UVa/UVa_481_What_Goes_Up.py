from bisect import *
import sys
sys.stdin = open('input.txt', 'r')


def reconstruct_print(end, a, p):
    s = []
    while p[end] >= 0:
        s.append(a[end])
        end = p[end]
    s.append(a[end])
    for i in range(len(s) - 1, -1, -1):
        print(s[i])


def solution(n, a):
    L = [None] * n
    L_id = [None] * n
    P = [None] * n
    lis = lis_end = 0
    for i in range(n):
        pos = bisect_left(L, a[i], 0, lis)
        L[pos] = a[i]
        L_id[pos] = i
        P[i] = L_id[pos - 1] if pos else -1
        if pos + 1 > lis:
            lis = pos + 1
            lis_end = i
    print(lis)
    print('-')
    reconstruct_print(lis_end, a, P)


a = []
while True:
    try:
        num = int(input())
        if not (num in a):
            a.append(num)
    except EOFError:
        solution(len(a), a)
        break
