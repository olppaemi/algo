# https://onlinejudge.org/external/112/11264.pdf

def solution(coins):
    answer = 1  # first coin
    summary = coins[0]

    for i in range(1, len(coins) - 1):
        if coins[i] + summary < coins[i + 1]:
            summary += coins[i]
            answer += 1
    return answer + 1  # last coin


tc = int(input())
for _ in range(tc):
    n = int(input())
    print(solution(list(map(int, input().split()))))
