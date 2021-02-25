# https://programmers.co.kr/learn/courses/30/lessons/43236


def solution(distance, rocks, n):
    INF = 1_000_000_001
    rocks.sort()
    start, end = 0, distance

    answer = 0
    while start <= end:
        prev = 0
        min_distance = INF
        removed_rocks = 0

        # 바위 사이의 최소거리
        mid = (start + end) // 2

        for rock in rocks:
            if rock - prev < mid:
                removed_rocks += 1
            else:
                min_distance = min(min_distance, rock - prev)
                prev = rock

        if removed_rocks > n:
            end = mid - 1
        else:
            answer = mid
            start = mid + 1
    return answer


print(solution(25, [2, 14, 11, 21, 17], 2))
