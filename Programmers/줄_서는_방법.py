# https://programmers.co.kr/learn/courses/30/lessons/12936

from math import factorial


def solution(n, k):
    answer = []
    num = list(range(1, n + 1))

    while n > 0:
        n -= 1
        quotient, remainder = divmod(k, factorial(n))
        if not remainder:
            quotient -= 1
        answer.append(num[quotient])
        num.remove(num[quotient])
        k = remainder

    return answer


print(solution(3, 5))
