# https://programmers.co.kr/learn/courses/30/lessons/60063

from collections import deque


def get_next_pos(cur1, cur2, board):
    X, Y = 0, 1
    DELTA = [(-1, 0), (1, 0), (0, 1), (0, -1)]
    next_pos = []

    for dx, dy in DELTA:  # 평행 이동
        nxt1 = (cur1[X] + dx, cur1[Y] + dy)
        nxt2 = (cur2[X] + dx, cur2[Y] + dy)
        if board[nxt1[X]][nxt1[Y]] == 0 and board[nxt2[X]][nxt2[Y]] == 0:
            next_pos.append({nxt1, nxt2})

    if cur1[X] == cur2[X]:  # 가로 방향
        UP, DOWN = -1, 1
        for d in [UP, DOWN]:
            if board[cur1[X] + d][cur1[Y]] == 0 and board[cur2[X] + d][cur2[Y]] == 0:
                next_pos.append({cur1, (cur1[X] + d, cur1[Y])})
                next_pos.append({cur2, (cur2[X] + d, cur2[Y])})
    elif cur1[Y] == cur2[Y]:  # 세로 방향
        LEFT, RIGHT = -1, 1
        for d in [LEFT, RIGHT]:
            if board[cur1[X]][cur1[Y] + d] == 0 and board[cur2[X]][cur2[Y] + d] == 0:
                next_pos.append({cur1, (cur1[X], cur1[Y] + d)})
                next_pos.append({cur2, (cur2[X], cur2[Y] + d)})
    return next_pos


def solution(board):
    N = len(board)
    new_board = [[1] * (N + 2) for _ in range(N + 2)]
    for i in range(N):
        for j in range(N):
            new_board[i + 1][j + 1] = board[i][j]

    now = {(1, 1), (1, 2)}
    q = deque([(now, 0)])
    visited = [now]

    while q:
        now, time = q.popleft()
        if (N, N) in now:
            return time
        now = list(now)
        for next_pos in get_next_pos(now[0], now[1], new_board):
            if next_pos not in visited:
                q.append((next_pos, time + 1))
                visited.append(next_pos)


print(solution([[0, 0, 0, 1, 1], [0, 0, 0, 1, 0], [
      0, 1, 0, 1, 1], [1, 1, 0, 0, 1], [0, 0, 0, 0, 0]]))
