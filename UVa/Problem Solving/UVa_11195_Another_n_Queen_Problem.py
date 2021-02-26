# https://onlinejudge.org/external/111/11195.pdf

def solution(board):
    answer = 0
    n = len(board)
    rw, ld, rd = [False] * 15, [False] * 30, [False] * 30

    def backtrack(c):
        nonlocal answer, rw, ld, rd
        if c == n:
            answer += 1
            return
        for r in range(n):
            if board[r][c] != '*' and not rw[r] and not ld[r - c + n - 1] and not rd[r + c]:
                rw[r] = ld[r - c + n - 1] = rd[r + c] = True
                backtrack(c + 1)
                rw[r] = ld[r - c + n - 1] = rd[r + c] = False

    backtrack(0)
    return answer


for count in range(1, 11):
    n = int(input())
    if not n:
        break
    board = []
    for _ in range(n):
        board.append(list(input()))
    print(f"Case {count}: {solution(board)}")
