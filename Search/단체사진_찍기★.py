# https://programmers.co.kr/learn/courses/30/lessons/1835

def solution(n, data):
    characters = ['A', 'C', 'F', 'J', 'M', 'N', 'R', 'T']
    position = [''] * 8
    checked = [False] * 8
    answer = 0

    def is_possible():
        for condition in data:
            cond = ord(condition[4]) - ord('0')

            for i in range(8):
                if position[i] == condition[0]:
                    f = i
                if position[i] == condition[2]:
                    t = i
            gap = abs(f - t) - 1
            if condition[3] == '=' and gap != cond:
                return False
            elif condition[3] == '<' and gap >= cond:
                return False
            elif condition[3] == '>' and gap <= cond:
                return False

        return True

    def dfs(idx):
        nonlocal answer
        if idx == 8 and is_possible():
            answer += 1
            return
        for j in range(8):
            if not checked[j]:
                checked[j] = True
                position[idx] = characters[j]
                dfs(idx + 1)
                checked[j] = False

    dfs(0)
    return answer


print(solution(2, ["N~F=0", "R~T>2"]))
print(solution(2, ["M~C<2", "C~M>1"]))
