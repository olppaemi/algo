# https://onlinejudge.org/external/1/108.pdf

def solution(n, a):
    for i in range(n):
        for j in range(n):
            if i > 0:
                a[i][j] += a[i - 1][j]  # if possible, add from top
            if j > 0:
                a[i][j] += a[i][j - 1]  # if possible, add from left
            if i > 0 and j > 0:
                a[i][j] -= a[i - 1][j - 1]  # avoid double count

    mx = -100*127*127  # the lowest possible value for this problem

    # sum of any sub-matrix (i, j) to (k, l) is
    # a[k][l] - a[i - 1][l] - a[k][j - 1] + a[i - 1][j - 1]
    for i in range(n):
        for j in range(n):  # start coordinate
            for k in range(i, n):
                for l in range(j, n):  # end coordinate
                    sub = a[k][l]
                    if i > 0:
                        sub -= a[i - 1][l]
                    if j > 0:
                        sub -= a[k][j - 1]
                    if i > 0 and j > 0:
                        sub += a[i - 1][j - 1]
                    mx = max(mx, sub)

    return mx


n = int(input())
arr = []
while len(arr) != n * n:
    arr.extend(list(map(int, input().split())))

arr = [arr[i:i + n] for i in range(0, len(arr), n)]
print(solution(n, arr))
