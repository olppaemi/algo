# https://www.acmicpc.net/problem/2667

def solution(n, graph):
    answer = []
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    def dfs(x, y):
        answer = 1
        graph[x][y] = 0

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n and graph[nx][ny]:
                answer += dfs(nx, ny)
        return answer

    for i in range(n):
        for j in range(n):
            if graph[i][j]:
                answer.append(dfs(i, j))
    answer.sort()
    return f'{len(answer)}\n' + '\n'.join(map(str, answer))


n = int(input())
graph = []
for _ in range(n):
    graph.append(list(map(int, input())))
print(solution(n, graph))
