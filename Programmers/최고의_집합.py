# https://programmers.co.kr/learn/courses/30/lessons/12938

def solution(n, s):
    if n > s:
        return [-1]

    answer = [s // n for _ in range(n)]
    for i in range(n - 1, n - (s % n) - 1, -1):
        answer[i] += 1

    return answer


print(solution(2, 9))
