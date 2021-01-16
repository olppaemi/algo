# https://programmers.co.kr/learn/courses/30/lessons/42861

parent = [i for i in range(101)]


def find(u):
    if parent[u] != u:
        parent[u] = find(parent[u])
    return parent[u]


def union(u, v):
    u = find(u)
    v = find(v)
    if u < v:
        parent[v] = u
    else:
        parent[u] = v


def solution(n, costs):
    answer = 0
    edges = [(cost, u, v) for u, v, cost in costs]
    edges.sort()

    for edge in edges:
        cost, u, v = edge
        if find(u) != find(v):
            union(u, v)
            answer += cost

    return answer


print(solution(4, [[0, 1, 1], [0, 2, 2], [1, 2, 5], [1, 3, 1], [2, 3, 8]]))
