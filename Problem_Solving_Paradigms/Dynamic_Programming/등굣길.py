# https://programmers.co.kr/learn/courses/30/lessons/42898

def solution(m, n, puddles):
    MOD = 1_000_000_007
    jido = [[0] * (m + 1) for i in range(n + 1)]
    jido[1][1] = 1

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if i == 1 and j == 1:
                continue
            if [j, i] in puddles:
                continue
            else:
                jido[i][j] = jido[i - 1][j] + jido[i][j - 1]
                jido[i][j] %= MOD

    return jido[-1][-1]


print(solution(4, 3, [[2, 2]]))
