# https://programmers.co.kr/learn/courses/30/lessons/49994

def solution(dirs):
    cur = (0, 0)
    visited = set()

    for d in dirs:
        if d == "U" and cur[1] + 1 <= 5:
            next = (cur[0], cur[1] + 1)
        elif d == "D" and cur[1] - 1 >= -5:
            next = (cur[0], cur[1] - 1)
        elif d == "R" and cur[0] + 1 <= 5:
            next = (cur[0] + 1, cur[1])
        elif d == "L" and cur[0] - 1 >= -5:
            next = (cur[0] - 1, cur[1])
        else:
            continue
        if not (cur + next in visited or next + cur in visited):
            visited.add(cur + next)

        cur = next

    return len(visited)


print(solution("ULURRDLLU"))
print(solution("LULLLLLLU"))
