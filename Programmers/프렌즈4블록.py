# https://programmers.co.kr/learn/courses/30/lessons/17679

from collections import deque


def solution(m, n, board):
    answer = 0
    board = [list(s) for s in board]

    def print_board(board):
        for i in range(len(board)):
            print(board[i])

    def remove_block(board):
        new_board = [board[i][:] for i in range(m)]
        for i in range(m - 1):
            for j in range(n - 1):
                if board[i][j] != "X" and board[i][j] == board[i][j + 1] == board[i + 1][j] == board[i + 1][j + 1]:
                    new_board[i][j] = "X"
                    new_board[i][j + 1] = "X"
                    new_board[i + 1][j] = "X"
                    new_board[i + 1][j + 1] = "X"
        return new_board

    def compare_board(board, new_board):
        diff = 0
        for i in range(m):
            for j in range(n):
                if board[i][j] != new_board[i][j]:
                    diff += 1
        return diff

    def restruct(board):
        for j in range(n):
            q = deque([])
            for i in range(m):
                if board[i][j] != 'X':
                    q.append(board[i][j])
            q.extendleft(['X'] * (m - len(q)))
            for i in range(m):
                board[i][j] = q.popleft()
        return board

    while True:
        new_board = remove_block(board)
        diff = compare_board(board, new_board)
        if diff == 0:
            break
        answer += diff
        board = restruct(new_board)

    return answer


print(solution(4, 5, ["CCBDE", "AAADE", "AAABF", "CCBBF"]))
