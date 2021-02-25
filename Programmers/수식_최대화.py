# https://programmers.co.kr/learn/courses/30/lessons/67257

from itertools import permutations


def calc(i, priority, expression):
    res = 0
    if i == 2:
        return str(eval(expression))
    if priority[i] == '*':
        res = eval('*'.join([calc(i + 1, priority, e)
                             for e in expression.split('*')]))
    if priority[i] == '+':
        res = eval('+'.join([calc(i + 1, priority, e)
                             for e in expression.split('+')]))
    if priority[i] == '-':
        res = eval('-'.join([calc(i + 1, priority, e)
                             for e in expression.split('-')]))
    return str(res)


def solution(expression):
    answer = 0
    operator = ['*', '+', '-']

    for order in permutations(operator):
        res = int(calc(0, order, expression))
        answer = max(answer, abs(res))
    return answer


print(solution("100-200*300-500+20"))
print(solution("50*6-3*2"))
