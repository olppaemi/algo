# https://programmers.co.kr/learn/courses/30/lessons/43162

def dfs(graph, now, visited):
    visited[now] = True

    for next in graph[now]:
        if not visited[next]:
            dfs(graph, next, visited)


def solution(n, computers):
    graph = [[] for i in range(n)]
    visited = [False] * n

    for i in range(1, n):
        for j in range(i):
            if computers[i][j]:
                graph[i].append(j)
                graph[j].append(i)

    answer = 0
    for i in range(n):
        if not visited[i]:
            dfs(graph, i, visited)
            answer += 1

    return answer


print(solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]))  # 2
print(solution(3, [[1, 1, 0], [1, 1, 1], [0, 1, 1]]))  # 1
