# https://programmers.co.kr/learn/courses/30/lessons/42890

from itertools import combinations


def solution(relation):
    ROWS, COLS = len(relation), len(relation[0])
    answer = 0

    def is_unique(attributes):
        check = set()
        for r in relation:
            check.add(tuple(r[i] for i in attributes))
        return True if len(check) == ROWS else False

    def is_minimal(attributes):
        if len(attributes) == 1:
            return True

        num_violation = 0
        for attrs in combinations(attributes, len(attributes) - 1):
            check = set()
            for r in relation:
                check.add(tuple(r[i] for i in attrs))
            if len(check) != len(relation):
                num_violation += 1
            else:
                return False
        return num_violation == len(attributes)

    for i in range(1, COLS + 1):
        for attrs in combinations(range(COLS), i):
            if is_unique(attrs) and is_minimal(attrs):
                answer += 1

    return answer


print(solution([["100", "ryan", "music", "2"],
                ["200", "apeach", "math", "2"],
                ["300", "tube", "computer", "3"],
                ["400", "con", "computer", "4"],
                ["500", "muzi", "music", "3"],
                ["600", "apeach", "music", "2"]]))
