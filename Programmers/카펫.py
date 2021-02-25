# https://programmers.co.kr/learn/courses/30/lessons/42842

def solution(brown, yellow):
    for i in range(1, int(yellow ** 0.5) + 1):
        if yellow % i == 0:
            j = yellow // i
            if 2*i + 2*j + 4 == brown:
                return [j + 2, i + 2]
