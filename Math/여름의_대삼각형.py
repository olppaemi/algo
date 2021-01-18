# https://level.goorm.io/exam/49087/%EC%97%AC%EB%A6%84%EC%9D%98-%EB%8C%80%EC%82%BC%EA%B0%81%ED%98%95/quiz/1

# 헤론 공식
def triangle_area(a, b, c):
    s = (a + b + c) / 2
    return (s * (s - a) * (s - b) * (s - c)) ** 0.5


def distance(p1, p2):
    return ((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2) ** 0.5


def solution(point):
    a, b, c = distance(point[0], point[1]), distance(
        point[1], point[2]), distance(point[2], point[0])
    return f"{triangle_area(a, b, c):.2f}"


point = []
for _ in range(3):
    x, y = map(int, input().split())
    point.append((x, y))
print(solution(point))
