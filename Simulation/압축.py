# https://programmers.co.kr/learn/courses/30/lessons/17684

def solution(msg):
    answer = []
    dictionary = {chr(ord('A') + i - 1): i for i in range(1, 27)}
    id = 27

    start = 0
    while start < len(msg):
        end = len(msg)
        while not (msg[start:end] in dictionary):
            end -= 1
        answer.append(dictionary[msg[start:end]])
        dictionary[msg[start:end + 1]] = id
        id += 1
        start += end - start

    return answer


print(solution("KAKAO"))
