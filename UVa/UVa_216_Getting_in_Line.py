# https://onlinejudge.org/external/2/216.pdf

from itertools import permutations
import sys


def distance(p1, p2):
    return (abs(p1[0] - p2[0]) ** 2 + abs(p1[1] - p2[1]) ** 2) ** 0.5


def solution(n, coords):
    graph = [[0] * n for _ in range(n)]
    min_perm, min_dist = None, 1e9

    for i in range(n):
        for j in range(i + 1, n):
            graph[i][j] = graph[j][i] = distance(coords[i], coords[j]) + 16

    for perm in permutations(range(n)):
        dist = sum(graph[perm[k]][perm[k + 1]] for k in range(n - 1))
        if dist < min_dist:
            min_dist = dist
            min_perm = perm
    for i in range(1, n):
        s, e = min_perm[i - 1], min_perm[i]
        x1, y1 = coords[s]
        x2, y2 = coords[e]
        print("Cable requirement to connect ({},{}) to ({},{}) is {:.2f} feet.".format(
            x1, y1, x2, y2, graph[s][e]))
    print("Number of feet of cable required is {:.2f}.".format(min_dist))


inp = iter(sys.stdin.readlines())
count = 1
while True:
    n = int(next(inp))
    if not n:
        break
    coords = [list(map(int, (next(inp).split()))) for _ in range(n)]
    print("**********************************************************")
    print(f"Network #{count}")
    count += 1
    solution(n, coords)
