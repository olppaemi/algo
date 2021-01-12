# https://programmers.co.kr/learn/courses/30/lessons/43105

def solution(triangle):
    HEIGHT = len(triangle)

    for i in range(1, HEIGHT):
        for j in range(len(triangle[i])):
            if j == i:
                triangle[i][j] += triangle[i - 1][j - 1]
            elif j == 0:
                triangle[i][j] += triangle[i - 1][j]
            else:
                triangle[i][j] += max(triangle[i - 1]
                                      [j - 1], triangle[i - 1][j])

    return max(triangle[HEIGHT - 1])


print(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]))
