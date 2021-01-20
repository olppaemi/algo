# https://www.acmicpc.net/problem/18406

num = list(map(int, list(input())))
n = len(num)

if sum(num[:n // 2]) == sum(num[n // 2:]):
    print("LUCKY")
else:
    print("READY")
