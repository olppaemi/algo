# https://programmers.co.kr/learn/courses/30/lessons/12953

from math import gcd


def solution(arr):

    def lcm(a, b):
        return a * b // gcd(a, b)

    answer = arr[0]
    for i in range(1, len(arr)):
        answer = lcm(answer, arr[i])

    return answer


print(solution([2, 6, 8, 14]))
print(solution([1, 2, 3]))
