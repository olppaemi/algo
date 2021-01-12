# https://onlinejudge.org/external/117/11742.pdf

def solution(n, constraints):
    answer = 0
    position = [-1] * n
    visited = [False] * n

    def possible():
        for c in constraints:
            p1, p2, cond = c
            f = position.index(p1)
            t = position.index(p2)
            gap = abs(f - t)

            if cond < 0 and gap < abs(cond):  # cond만큼 떨어져 있지 못하다면, 실패
                return False
            elif cond > 0 and gap > cond:  # cond만큼 가깝지 않다면, 실패
                return False
        return True

    def dfs(i):
        nonlocal answer
        if i == n and possible():
            answer += 1
            return
        for j in range(n):
            if not visited[j]:
                visited[j] = True
                position[j] = i
                dfs(i + 1)
                visited[j] = False

    dfs(0)
    return answer


while True:
    m, n = map(int, input().split())
    if not m and not n:
        break
    constraints = []
    for i in range(n):
        constraints.append(list(map(int, input().split())))
    print(solution(m, constraints))
