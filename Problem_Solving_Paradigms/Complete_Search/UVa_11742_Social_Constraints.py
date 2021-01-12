# https://onlinejudge.org/external/117/11742.pdf

def solution(n, constraints):
    from itertools import permutations
    answer = 0

    def possible(position):
        for c in constraints:
            p1, p2, cond = c
            f = position.index(p1)
            t = position.index(p2)
            gap = abs(f - t)

            if cond < 0 and gap < abs(cond):
                return False
            elif cond > 0 and gap > cond:
                return False
        return True

    for perm in permutations(range(n)):
        if possible(perm):
            answer += 1

    return answer


while True:
    m, n = map(int, input().split())
    if not m and not n:
        break
    constraints = []
    for i in range(n):
        constraints.append(list(map(int, input().split())))
    print(solution2(m, constraints))
