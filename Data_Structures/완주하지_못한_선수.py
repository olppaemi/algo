# https://programmers.co.kr/learn/courses/30/lessons/42576

def solution(participant, completion):
    participant.sort()
    completion.sort()

    for i in range(len(completion)):
        if participant[i] != completion[i]:
            return participant[i]
    return participant[-1]


def solution2(participant, completion):
    from collections import Counter
    answer = Counter(participant) - Counter(completion)
    return list(answer.keys())[0]


print(solution(["leo", "kiki", "eden"], ["eden", "kiki"]))
