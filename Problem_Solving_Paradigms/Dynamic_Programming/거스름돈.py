# https://programmers.co.kr/learn/courses/30/lessons/12907

def solution(n, money):
    table = [[0] * (n + 1) for _ in range(len(money))]
    table[0][0] = 1

    # 동전의 최솟값으로 만들 수 있는 값들
    for i in range(money[0], n + 1, money[0]):
        table[0][i] = 1

    for i in range(1, len(money)):
        for j in range(n + 1):
            if j >= money[i]:
                table[i][j] = (
                    table[i - 1][j] + table[i][j - money[i]]) % 1_000_000_007
            else:
                table[i][j] = table[i - 1][j]

    return table[-1][-1]


def solution2(n, money):
    dp = [1] + [0] * n
    for c in money:
        for i in range(c, n + 1):
            dp[i] += dp[i - c]
    return dp[-1]


print(solution(5, [1, 2, 5]))
