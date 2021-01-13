# http://uva.onlinejudge.org/external/124/12455.pdf

def solution(n, bars):
    p = len(bars)
    for i in range(1 << p):  # 0 ~ 2**n - 1
        sum = 0
        for j in range(p):  # check membership, O(n)
            if i & (1 << j):  # test if bit 'j' is turned on in subset 'i'
                sum += bars[j]
        if sum == n:  # the answer is found
            return "YES"
    return "NO"


test_case = int(input())
for count in range(test_case):
    n = int(input())
    p = int(input())
    bars = list(map(int, input().split()))
    print(solution(n, bars))
