# https://www.acmicpc.net/problem/1654

import sys
input = sys.stdin.readline

k, n = map(int, input().split())
lines = []

for _ in range(k):
    lines.append(int(input()))

start = 1
end = max(lines)

result = 0
while start <= end:
    total = 0
    mid = (start + end) // 2

    for line in lines:
        total += line // mid

    if total < n:
        end = mid - 1
    else:
        start = mid + 1
        result = mid

print(result)
