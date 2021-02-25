# https://programmers.co.kr/learn/courses/30/lessons/17687

def solution(n, t, m, p):
    answer = ''

    def convert(num):
        DIGITS = list('0123456789ABCDEF')
        if num == 0:
            return DIGITS[0]

        answer = ''
        while num:
            q, r = divmod(num, n)
            answer += DIGITS[r]
            num = q

        return answer[::-1]

    def next_value():
        i = 0
        while True:
            value = list(convert(i))
            for v in value:
                yield v
            i += 1

    for i, num in enumerate(next_value()):
        if len(answer) == t:
            break
        if i % m == p - 1:
            answer += num

    return answer


print(solution(2, 4, 2, 1))
print(solution(16, 16, 2, 1))
print(solution(16, 16, 2, 2))
