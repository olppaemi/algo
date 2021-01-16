# https://programmers.co.kr/learn/courses/30/lessons/67258

from collections import defaultdict


def solution(gems):
    gems_len, gems_kind = len(gems), len(set(gems))
    left, right = 0, 0
    candidates = []
    subset = defaultdict(int)

    mn = gems_len + 1
    answer = [0, 0]

    while left < gems_len:
        if len(subset) < gems_kind and right < gems_len:
            subset[gems[right]] += 1
            right += 1
        else:
            subset[gems[left]] -= 1
            if subset[gems[left]] == 0:
                subset.pop(gems[left], None)
            left += 1

        if len(subset) == gems_kind:
            if right - left < mn:
                mn = right - left
                answer = [left + 1, right]

    return answer


print(solution(["DIA", "RUBY", "RUBY", "DIA",
                "DIA", "EMERALD", "SAPPHIRE", "DIA"]))
print(solution(["AA", "AB", "AC", "AA", "AC"]))
print(solution(["XYZ", "XYZ", "XYZ"]))
print(solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"]))
