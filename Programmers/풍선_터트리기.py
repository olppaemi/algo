# https://programmers.co.kr/learn/courses/30/lessons/68646

def solution(a):
    m, n = 2e9, 2e9
    prefix_min = [m := min(m, v) for v in a[:-2]]
    suffix_min = [n := min(n, v) for v in reversed(a[2:])]
    return sum((x > y or z > y for x, y, z in zip(prefix_min, a[1:-1], reversed(suffix_min)))) + 2


def solution2(a):
    answer = 2
    n = len(a)
    if n <= 2:
        return n

    INF = 2e9
    prefix_min = [INF] * n
    suffix_min = [INF] * n
    prefix_min[0] = a[0]
    suffix_min[n - 1] = a[n - 1]

    for i in range(1, n):
        if a[i] < prefix_min[i - 1]:
            prefix_min[i] = a[i]
        else:
            prefix_min[i] = prefix_min[i - 1]

    for i in range(n - 2, -1, -1):
        if a[i] < suffix_min[i + 1]:
            suffix_min[i] = a[i]
        else:
            suffix_min[i] = suffix_min[i + 1]

    for i in range(1, n - 1):
        if prefix_min[i] < a[i] and suffix_min[i] < a[i]:
            continue
        answer += 1

    return answer


print(solution([9, -1, -5]))
print(solution([-16, 27, 65, -2, 58, -92, -71, -68, -61, -33]))
