def solution(stones, k):
    answer = 0
    start, end = 0, sum(stones)

    ########################################

    def possible(num):
        succession = 0
        for stone in stones:
            if stone < num:
                succession += 1
            else:
                succession = 0
            if succession >= k:
                return False
        return True
    ########################################

    while start <= end:
        mid = (start + end) // 2

        if possible(mid):
            answer = mid
            start = mid + 1
        else:
            end = mid - 1

    return answer


print(solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3))
