# https://programmers.co.kr/learn/courses/30/lessons/43163
from collections import deque


def can_change(a, b):
    answer = len(a)
    for c1, c2 in zip(a, b):
        if c1 == c2:
            answer -= 1
    return answer == 1


def solution(begin, target, words):
    if not (target in words):
        return 0

    words.append(begin)
    n = len(words)

    graph = [[] for i in range(n)]
    for i in range(1, n):
        for j in range(i):
            if can_change(words[i], words[j]):
                graph[i].append(j)
                graph[j].append(i)

    START, END = n - 1, words.index(target)
    q = deque([START])
    distance = [-1] * n
    distance[START] = 0

    while q:
        now = q.popleft()
        if words[now] == "target":
            break

        for next in graph[now]:
            if distance[next] == -1:
                distance[next] = distance[now] + 1
                q.append(next)

    return distance[END] if distance[END] != -1 else 0


print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))  # 4
print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log"]))  # 0
