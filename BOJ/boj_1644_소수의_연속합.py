def solution(n):

    def sieve():
        num = [True] * (n + 1)
        for i in range(2, int(n ** 0.5) + 1):
            if num[i]:
                for j in range(i * i, n + 1, i):
                    num[j] = False
        prime = []
        for i in range(2, n + 1):
            if num[i]:
                prime.append(i)
        return prime

    prime = sieve()
    k = len(prime)
    answer, s, left, right = 0, 0, 0, 0

    while left < k:
        if s < n and right < k:
            s += prime[right]
            right += 1
        else:
            s -= prime[left]
            left += 1
        if s == n:
            answer += 1

    return answer


n = int(input())
print(solution(n))
