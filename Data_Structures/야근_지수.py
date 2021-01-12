from heapq import heapify, heappop, heappush


def solution(n, works):
    # 야근을 할 필요가 없을 때
    if n >= sum(works):
        return 0

    works = list(map(lambda x: -x, works))
    heapify(works)

    for i in range(n):
        m = heappop(works)
        if m == 0:
            break
        heappush(works, m + 1)

    return sum(map(lambda x: x * x, works))


print(solution(4, [4, 3, 3]))
print(solution(1, [2, 1, 2]))
print(solution(3, [1, 1]))
