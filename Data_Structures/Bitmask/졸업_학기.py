# https://level.goorm.io/exam/43247/%EC%A1%B8%EC%97%85-%ED%95%99%EA%B8%B0/quiz/1

def make_bitset(a):
    bitset = []
    for l in a:
        tmp = 0
        for i in l:
            tmp |= (1 << i)
        bitset.append(tmp)
    return bitset


'''
N: 전공 과목의수
K: 들어야 할 과목의 수
M: 학기의 수
L: 한 학기에 최대로 들을 수 있는 과목의 수
'''


def solution(N, K, M, L, prerequisite, classes):
    INF = 2e9
    cache = [[INF] * (1 << N) for _ in range(M)]
    prerequisite = make_bitset(prerequisite)
    classes = make_bitset(classes)

    def graduate(semester, taken):
        nonlocal N, K, M, L, prerequisite, classes

        # k개 이상의 과목을 이미 들은 경우
        if bin(taken).count('1') >= K:
            return 0
        # m 학기가 전부 지난 경우
        if semester == M:
            return INF
        if cache[semester][taken] == INF:
            # 이번 학기에 들을 수 있는 과목 중 아직 듣지 않은 과목들
            can_take = classes[semester] & ~taken

            # 선수 과목을 다 듣지 않은 과목들을 걸러낸다.
            for i in range(N):
                if can_take & (1 << i) and (taken & prerequisite[i]) != prerequisite[i]:
                    can_take &= ~(1 << i)

            # 이 집합의 모든 부분 집합을 순회한다.
            take = can_take
            while take > 0:
                if bin(take).count('1') > L:
                    pass
                else:
                    cache[semester][taken] = min(
                        cache[semester][taken], graduate(semester + 1, taken | take) + 1)
                take = (take - 1) & can_take

            # 이번 학기에 아무 것도 듣지 않는 경우
            cache[semester][taken] = min(
                cache[semester][taken], graduate(semester + 1, taken))

        return cache[semester][taken]

    answer = graduate(0, 0)
    return answer if answer != INF else "IMPOSSIBLE"


test_case = int(input())
for _ in range(test_case):

    n, k, m, l = map(int, input().split())
    prerequisite = []
    classes = []
    for _ in range(n):
        prerequisite.append(list(map(int, input().split()))[1:])
    for _ in range(m):
        classes.append(list(map(int, input().split()))[1:])
    print(solution(n, k, m, l, prerequisite, classes))
