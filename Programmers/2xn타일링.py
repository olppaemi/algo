# https://programmers.co.kr/learn/courses/30/lessons/12900

def solution(n):
    dp = [0] * (n + 1)
    dp[1] = 1
    dp[2] = 2

    for i in range(3, n + 1):
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1_000_000_007

    return dp[n]


def solution2(n):
    a, b = 0, 1

    for i in range(n):
        a, b = b, a + b % 1_000_000_007

    return b % 1_000_000_007


print(solution2(4))
