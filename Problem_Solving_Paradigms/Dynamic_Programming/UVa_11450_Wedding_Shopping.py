# https://onlinejudge.org/external/114/11450.pdf

def solution():
    M, C = 0, 0
    price = []
    memo = []

    def shop(money, g):
        if money < 0:  # 실패, 큰 음수값을 반환한다.
            return -1_000_000_000
        if g == C:  # 마지막 예복을 구매했으므로, 완료
            return M - money
        if memo[money][g] != -1:
            return memo[money][g]
        answer = -1
        # 모든 품목을 시도한다.
        for model in range(1, price[g][0] + 1):
            answer = max(answer, shop(money - price[g][model], g + 1))
        memo[money][g] = answer
        return answer

    test_case = int(input())
    for _ in range(test_case):
        M, C = map(int, input().split())  # 쓸 수 있는 돈, 사야할 의상 수
        price = []  # price[g (<= 20)][model (<= 20)]
        for i in range(C):
            price.append(list(map(int, input().split())))
        # memo[money (<= 200)][g (<= 20)]
        memo = [[-1] * C for _ in range(M + 1)]
        score = shop(M, 0)
        if score < 0:
            print("no solution")
        else:
            print(score)


def solution2():
    M, C = 0, 0

    test_case = int(input())
    for _ in range(test_case):
        M, C = map(int, input().split())
        price = []
        for i in range(C):
            price.append(list(map(int, input().split())))

        reachable = [[False] * (M + 1) for i in range(C)]
        for g in range(1, price[0][0] + 1):
            if M - price[0][g] >= 0:
                reachable[0][M - price[0][g]] = True

        for g in range(1, C):
            for money in range(M):
                if reachable[g - 1][money]:
                    for k in range(1, price[g][0] + 1):
                        if money - price[g][k] >= 0:
                            reachable[g][money - price[g][k]] = True

        for money in range(M):
            if reachable[C - 1][money]:
                print(M - money)
                break
        else:
            print("no solution")


solution2()
