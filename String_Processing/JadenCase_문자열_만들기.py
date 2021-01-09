# https://programmers.co.kr/learn/courses/30/lessons/12951

def solution(s):
    words = s.split(' ')
    for i in range(len(words)):
        if words[i] != '':
            words[i] = words[i][0].upper() + words[i][1:].lower()

    return ' '.join(words)


print(solution("3people unFollowed me"))
print(solution("for the last week"))
