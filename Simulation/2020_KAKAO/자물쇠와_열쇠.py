# https://programmers.co.kr/learn/courses/30/lessons/60059

def solution(key, lock):
    N, M = len(lock), len(key)
    new_lock = [[0] * (3 * N) for _ in range(3 * N)]

    def rotate(key):
        return list(zip(*reversed(key)))

    def check():
        for i in range(N, N * 2):
            for j in range(N, N * 2):
                if new_lock[i][j] != 1:
                    return False
        return True

    for i in range(N):
        for j in range(N):
            new_lock[i + N][j + N] = lock[i][j]

    for rotation in range(4):
        for x in range(N * 2):
            for y in range(N * 2):

                for i in range(M):
                    for j in range(M):
                        new_lock[x + i][y + j] += key[i][j]

                if check() == True:
                    return True

                for i in range(M):
                    for j in range(M):
                        new_lock[x + i][y + j] -= key[i][j]
        key = rotate(key)

    return False


print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]],
               [[1, 1, 1], [1, 1, 0], [1, 0, 1]]))
