# https://programmers.co.kr/learn/courses/30/lessons/12914

def solution(n):
    MOD = 1234567
    a, b = 0, 1

    for i in range(n):
        a, b = b, (a + b) % MOD
    return b % MOD


print(solution(4))
print(solution(3))
