import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')


def solution(n, l, w, circle):
    interval = []
    start, end = l, 0
    for pos, radius in circle:
        dx = (radius ** 2 - (w / 2) ** 2) ** 0.5
        left = max(0, pos - dx)
        right = min(pos + dx, l)
        interval.append((left, right))

        start = min(start, left)
        end = max(end, right)

    if start != 0 or end != l:
        return -1

    interval.sort(key=lambda x: (x[0], -x[1]))

    answer = 0
    i, end = 0, 0
    while i < n and end < l:
        if interval[i][0] <= end:
            answer += 1

            for j in range(i + 1, n):
                if interval[j][0] <= end and interval[j][1] > interval[i][1]:
                    i = j
                elif interval[j][0] > end:
                    break
            end = interval[i][1]
        else:
            answer = -1
            break

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
