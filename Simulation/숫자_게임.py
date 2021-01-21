# https://programmers.co.kr/learn/courses/30/lessons/12987

from heapq import heapify, heappop


def solution(A, B):
    if min(A) > max(B):
        return 0
    answer = 0
    A.sort(reverse=True)
    B = [-i for i in B]
    heapify(B)

    for a in A:
        if a >= abs(B[0]):
            continue
        heappop(B)
        answer += 1
    return answer


print(solution([5, 1, 3, 7], [2, 2, 6, 8]))
print(solution([2, 2, 2, 2], [1, 1, 1, 1]))
