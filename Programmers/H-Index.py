# https://programmers.co.kr/learn/courses/30/lessons/42747

def solution(citations):
    citations.sort()
    l = len(citations)

    for i in range(l):
        # 논문의 인용된 횟수 >= 인용된 논문의 개수
        if citations[i] >= l - i:
            return l - i
    return 0
