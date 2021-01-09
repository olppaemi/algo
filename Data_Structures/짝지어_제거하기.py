# https://programmers.co.kr/learn/courses/30/lessons/12973

def solution(s):
    stack = []
    for c in s:
        if stack:
            if c != stack[-1]:
                stack.append(c)
            else:
                stack.pop()
        else:
            stack.append(c)

    return 1 if not stack else 0


print(solution("baabaa"))
print(solution("cdcd"))
