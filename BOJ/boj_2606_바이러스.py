# https://www.acmicpc.net/problem/2606

def solution(start, graph):
    from collections import deque
    visited = [False] * len(graph)
    q = deque([start])
    visited[start] = True

    while q:
        now = q.popleft()
        for nxt in graph[now]:
            if not visited[nxt]:
                visited[nxt] = True
                q.append(nxt)

    return sum(visited) - 1


v = int(input())
e = int(input())
graph = [[] for i in range(v + 1)]

for i in range(e):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

print(solution(1, graph))
