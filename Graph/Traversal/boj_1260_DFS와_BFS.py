# https://www.acmicpc.net/problem/1260

def dfs(now, graph):
    answer = []
    visited = [False] * len(graph)

    def traversal(now):
        visited[now] = True
        answer.append(now)

        for next in graph[now]:
            if not visited[next]:
                traversal(next)

    traversal(now)
    return answer


def bfs(start, graph):
    from collections import deque
    answer = []

    visited = [False] * len(graph)
    q = deque([start])
    visited[start] = True

    while q:
        now = q.popleft()
        answer.append(now)

        for next in graph[now]:
            if not visited[next]:
                visited[next] = True
                q.append(next)

    return answer


n, m, v = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for l in graph:
    l.sort()

print(' '.join(map(str, dfs(v, graph))))
print(' '.join(map(str, bfs(v, graph))))
