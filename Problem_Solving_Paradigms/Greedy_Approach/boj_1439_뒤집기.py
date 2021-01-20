def solution(s):
    count0 = 0  # 전부 0으로 바꾸는 경우
    count1 = 0  # 전부 1로 바꾸는 경우

    if s[0] == '1':
        count0 += 1
    else:
        count1 += 1

    for i in range(1, len(s) - 1):
        if s[i] != s[i + 1]:
            if s[i + 1] == '1':
                count0 += 1
            else:
                count1 += 1

    return min(count0, count1)


s = input()
print(solution(s))
