# https://programmers.co.kr/learn/courses/30/lessons/49191

from collections import defaultdict


def solution(n, results):
    win = defaultdict(set)
    lose = defaultdict(set)

    for winner, loser in results:
        win[winner].add(loser)
        lose[loser].add(winner)

    for i in range(1, n + 1):
        # i를 이긴 사람들은
        # i가 이긴 사람도 이긴다.
        for winner in lose[i]:
            win[winner] |= win[i]
        # i에게 진 사람들은
        # i가 진 사람에게도 진다
        for loser in win[i]:
            lose[loser] |= lose[i]

    answer = 0
    for i in range(1, n + 1):
        if len(win[i]) + len(lose[i]) == n - 1:
            answer += 1
    return answer


print(solution(5, [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))
