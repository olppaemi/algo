# https://programmers.co.kr/learn/courses/30/lessons/17677

from collections import defaultdict


def solution(str1, str2):
    ms1, ms2 = defaultdict(int), defaultdict(int)
    str1 = str1.upper()
    str2 = str2.upper()

    for i in range(len(str1) - 1):
        if str1[i].isalpha() and str1[i + 1].isalpha():
            ms1[str1[i:i+2]] += 1

    for i in range(len(str2) - 1):
        if str2[i].isalpha() and str2[i + 1].isalpha():
            ms2[str2[i:i+2]] += 1

    union_set = set(ms1.keys()) | set(ms2.keys())
    intersection_set = set(ms1.keys()) & set(ms2.keys())

    num_union = 0
    num_interection = 0

    for key in union_set:
        num_union += max(ms1[key], ms2[key])

    for key in intersection_set:
        num_interection += min(ms1[key], ms2[key])

    return int(num_interection / num_union * 65536) if num_union else 65536


print(solution("FRANCE", "french"))
print(solution("handshake", "shake hands"))
