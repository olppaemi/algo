# https://www.acmicpc.net/problem/3273

def solution(n, a, x):
    answer = 0
    head, tail = 0, n - 1
    while head < tail:
        s = a[head] + a[tail]
        if s == x:
            answer += 1
            head += 1
            tail -= 1
        elif s > x:
            tail -= 1
        else:
            head += 1

    return answer


n = int(input())
a = list(map(int, input().split()))
a.sort()
x = int(input())
print(solution(n, a, x))
