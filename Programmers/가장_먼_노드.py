# https://programmers.co.kr/learn/courses/30/lessons/49189

from collections import deque


def solution(n, edges):
    graph = [[] for i in range(n + 1)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    distance = [-1] * (n + 1)
    q = deque([1])
    distance[1] = 0

    while q:
        now = q.popleft()

        for next in graph[now]:
            if distance[next] < 0:
                q.append(next)
                distance[next] = distance[now] + 1

    max_dist = max(distance)
    return len([v for v in range(1, n + 1) if distance[v] == max_dist])


print(solution(6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))
