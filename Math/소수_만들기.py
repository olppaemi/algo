from itertools import combinations


def solution(nums):
    answer = 0

    def is_prime(n):
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                return False
        return True

    for comb in combinations(nums, 3):
        if is_prime(sum(comb)):
            answer += 1

    return answer


print(solution([1, 2, 3, 4]))
print(solution([1, 2, 7, 6, 4]))
