import sys
sys.stdin = open('input.txt')


def solution(n, cuts):
    memo = [[-1] * 60 for _ in range(60)]

    def search(left, right):
        if left + 1 == right:
            return 0
        if memo[left][right] == -1:
            memo[left][right] = 2e9
            for idx in range(left + 1, right):
                memo[left][right] = min(memo[left][right], search(
                    left, idx) + search(idx, right) + cuts[right] - cuts[left])
        return memo[left][right]

    return search(0, n + 1)


inp = iter(sys.stdin.readlines())
while True:
    l = int(next(inp))
    if not l:
        break
    n = int(next(inp))
    cuts = list(map(int, next(inp).split()))
    cuts = [0] + cuts + [l]
    print(f"The minimum cutting is {solution(n, cuts)}.")
