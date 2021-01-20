# https://programmers.co.kr/learn/courses/30/lessons/60057

def solution(s):
    N = len(s)
    answer = N
    for step in range(1, N // 2 + 1):
        compressed = ""
        prev = s[:step]
        count = 1
        for i in range(step, N, step):
            if prev == s[i:i + step]:
                count += 1
            else:
                compressed += str(count) + prev if count >= 2 else prev
                prev = s[i:i + step]
                count = 1
        compressed += str(count) + prev if count >= 2 else prev
        answer = min(answer, len(compressed))

    return answer


print(solution("aabbaccc"))
print(solution("ababcdcdababcdcd"))
print(solution("abcabcabcabcdededededede"))
