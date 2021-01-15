# https://programmers.co.kr/learn/courses/30/lessons/12921

def solution(n):
    num = set(range(2, n + 1))

    for i in range(2, int(n ** 0.5) + 1):
        if i in num:
            num -= set(range(i * i, n + 1, i))
    return len(num)


def solution2(n):
    num = [True] * (n + 1)
    for i in range(2, int(n ** 0.5) + 1):
        if num[i]:
            for j in range(i * i, n + 1, i):
                num[j] = False
    answer = 0
    for i in range(2, n + 1):
        if num[i]:
            answer += 1
    return answer
