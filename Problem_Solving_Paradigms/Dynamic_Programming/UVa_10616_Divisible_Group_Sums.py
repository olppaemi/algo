# https://onlinejudge.org/external/106/10616.pdf

import sys
input = sys.stdin.readline


def solution(n, m, d, num):
    table = [[[-1 for _ in range(d)] for _ in range(m)] for _ in range(n)]

    def dfs(idx, cnt, sum):
        if cnt == m:
            if sum == 0:
                return 1
            return 0
        if idx >= n:
            return 0

        if table[idx][cnt][sum] >= 0:
            return table[idx][cnt][sum]

        temp = (sum + num[idx]) % d
        if temp < 0:
            temp += d

        not_skip = dfs(idx + 1, cnt + 1, temp)
        skip = dfs(idx + 1, cnt, sum % d)

        table[idx][cnt][sum] = not_skip + skip
        return table[idx][cnt][sum]

    return dfs(0, 0, 0)


count = 1
while True:
    n, q = map(int, input().split())
    if not n and not q:
        break
    numbers = []
    for i in range(n):
        numbers.append(int(input()))
    table = [[] for i in range(11)]
    print(f"SET {count}:")
    count += 1
    for i in range(1, q + 1):
        d, m = map(int, input().split())
        print(f"QUERY {i}: ", end="")
        print(solution(n, m, d, numbers))
