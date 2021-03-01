# https://www.acmicpc.net/problem/1806

def solution(n, s, a):
    answer = n + 1
    left, right = 0, 0
    ssum = 0
    while left < n:
        if ssum < s and right < n:
            ssum += a[right]
            right += 1
        else:
            ssum -= a[left]
            left += 1
        if ssum >= s:
            answer = min(answer, right - left)

    return answer if answer != n + 1 else 0


n, s = map(int, input().split())
a = list(map(int, input().split()))
print(solution(n, s, a))
