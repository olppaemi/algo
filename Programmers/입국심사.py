# https://programmers.co.kr/learn/courses/30/lessons/43238

def possible(n, times, total_time):
    return sum([total_time // t for t in times]) >= n


def solution(n, times):
    start, end = 0, max(times) * n

    answer = 0
    while start <= end:
        mid = (start + end) // 2
        if possible(n, times, mid):
            answer = mid
            end = mid - 1
        else:
            start = mid + 1
    return answer


print(solution(6, [7, 10]))  # 28
