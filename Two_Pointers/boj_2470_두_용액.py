# https://www.acmicpc.net/problem/2470

def solution(n, a):
    a.sort()
    left, right = 0, n - 1
    mn, left_value, right_value = 2e9, 0, 0

    while left < right:
        s = a[left] + a[right]
        if abs(s) < abs(mn):
            mn = s
            left_value = a[left]
            right_value = a[right]
        if s < 0:
            left += 1
        else:
            right -= 1

    if left_value > right_value:
        left_value, right_value = right_value, left_value

    print(f"{left_value} {right_value}")


n = int(input())
a = list(map(int, input().split()))
solution(n, a)
