# https://programmers.co.kr/learn/courses/30/lessons/43164

from collections import defaultdict


def dfs(routes):
    stack = ["ICN"]
    path = []  # 경로를 저장

    # 스택이 빌때 까지
    while len(stack) > 0:
        top = stack[-1]
        # 공항에서 출발하는 표가 없으면 또는 있지만 티켓을 다 써버린 경우
        if top not in routes or len(routes[top]) == 0:
            path.append(stack.pop())
        else:
            stack.append(routes[top].pop(0))
    return path[::-1]  # 역순으로 출력


def solution(tickets):
    routes = defaultdict(list)

    # 인접 리스트 그래프 생성
    for u, v in tickets:
        routes[u].append(v)

    # 알파벳 순으로 정렬
    for v in routes:
        routes[v].sort()

    return dfs(routes)


print(solution([["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]))
print(solution([["ICN", "SFO"], ["ICN", "ATL"], [
      "SFO", "ATL"], ["ATL", "ICN"], ["ATL", "SFO"]]))
print(solution([["ICN", "AAA"], ["ICN", "BBB"], ["BBB", "ICN"]]))
