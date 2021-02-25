# https://programmers.co.kr/learn/courses/30/lessons/12952

def solution(n):
    answer = 0
    rw, ld, rd = [False] * 15, [False] * 30, [False] * 30

    def backtrack(c):
        nonlocal answer, rw, ld, rd
        if c == n:
            answer += 1
            return
        for r in range(n):
            if not rw[r] and not ld[r - c + n - 1] and not rd[r + c]:
                rw[r] = ld[r - c + n - 1] = rd[r + c] = True
                backtrack(c + 1)
                rw[r] = ld[r - c + n - 1] = rd[r + c] = False

    backtrack(0)
    return answer


print(solution(4))
