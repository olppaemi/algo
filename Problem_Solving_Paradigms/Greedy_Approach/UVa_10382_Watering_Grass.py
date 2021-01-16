# http://uva.onlinejudge.org/external/103/10382.pdf

def solution(n, l, w, circle):
    LEFT, RIGHT = 0, 1
    interval = []
    for pos, radius in circle:
        if radius > w / 2:
            dx = (radius ** 2 - (w / 2) ** 2) ** 0.5
            left = pos - dx
            right = pos + dx
            interval.append((left, right))

    n = len(interval)
    interval.sort(key=lambda x: x[0])

    answer = 0
    i, covered, next_covered = 0, 0, 0

    while i < n:
        pos = -1
        while i < n and interval[i][LEFT] <= covered:
            if interval[i][RIGHT] > next_covered:
                next_covered = interval[i][RIGHT]
                pos = i
            i += 1
        if pos < 0:
            break

        answer += 1
        covered = next_covered
        if covered >= l:
            break
        i = pos + 1

    if covered < l:
        return -1
    else:
        return answer


while True:
    try:
        n, l, w = map(int, input().split())
        circle = []
        for _ in range(n):
            circle.append(list(map(int, input().split())))
        print(solution(n, l, w, circle))
    except EOFError:
        break
