# https://programmers.co.kr/learn/courses/30/lessons/12904

def solution(s):
    for length in range(len(s), 0, -1):
        for start in range(len(s) - length + 1):
            for i in range(length // 2 + 1):
                if s[start + i] != s[start + length - i - 1]:
                    break
            else:
                return length


print(solution("abcdcba"))
print(solution("abacde"))
