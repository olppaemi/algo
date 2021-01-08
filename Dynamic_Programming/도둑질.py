# https://programmers.co.kr/learn/courses/30/lessons/42897

def solution(money):
    n = len(money)
    dp = [0] * (n - 1)  # 처음 집을 훔치고 마지막 집을 안 터는 경우
    dp2 = [0] * n  # 처음 집을 훔치지 않는 경우

    # 처음 집을 훔친다.
    dp[0] = money[0]
    dp[1] = money[0]

    for i in range(2, n - 1):
        dp[i] = max(money[i] + dp[i - 2], dp[i - 1])

    # 처음 집을 훔치지 않는다.
    dp2[0] = 0
    dp2[1] = money[1]

    for i in range(2, n):
        dp2[i] = max(money[i] + dp2[i - 2], dp2[i - 1])

    return max(dp[-1], dp2[-1])


print(solution([1, 2, 3, 1]))
