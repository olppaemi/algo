# https://onlinejudge.org/external/7/725.pdf

def solution(n):
    answer = []
    for fghij in range(1234, 98765 // n + 1):
        used = [False] * 10
        abcde = fghij * n
        if fghij < 10000:
            used[0] = True
        tmp = abcde
        while tmp:
            used[tmp % 10] = True
            tmp //= 10
        tmp = fghij
        while tmp:
            used[tmp % 10] = True
            tmp //= 10
        if sum(used) == 10:
            answer.append(f"{abcde:05} / {fghij:05} = {n}")
    return answer


f = False
while True:
    n = int(input())
    if not n:
        break
    if f:
        print()
    answer = solution(n)
    if answer:
        for ans in answer:
            print(ans)
    else:
        print(f"There are no solutions for {n}.")
    f = True
