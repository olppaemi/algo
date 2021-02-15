# https://www.acmicpc.net/problem/2042

import sys
input = sys.stdin.readline


class FTree:
    def __init__(self, a):
        self.n = len(a)
        self.bit = [0] * (self.n + 1)

        for i in range(1, self.n + 1):
            self.bit[i] += a[i - 1]
            if i + self.lsone(i) <= self.n:
                self.bit[i + self.lsone(i)] += self.bit[i]

    def lsone(self, s):
        return s & (-s)

    def add(self, idx, val):
        while idx <= self.n:
            self.bit[idx] += val
            idx += self.lsone(idx)

    def prefix_sum(self, idx):
        answer = 0
        while idx > 0:
            answer += self.bit[idx]
            idx -= self.lsone(idx)
        return answer

    def sum(self, left, right):
        return self.prefix_sum(right) - self.prefix_sum(left - 1)


N, M, K = map(int, input().split())
arr = [0] * N
for i in range(N):
    arr[i] = int(input())

ft = FTree(arr)

for _ in range(M + K):
    a, b, c = map(int, input().split())
    if a == 1:
        ft.add(b, c - arr[b-1])
        arr[b - 1] = c
    elif a == 2:
        print(ft.sum(b, c))
