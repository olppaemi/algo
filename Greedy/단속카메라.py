# https://programmers.co.kr/learn/courses/30/lessons/42884

def solution(routes):
    answer = 0
    ENTER, EXIT, N = 0, 1, len(routes)
    recorded = [False] * N
    camera = -30000

    # 먼저 나가는 자동차를 기준으로 정렬
    routes.sort(key=lambda x: x[1])
    for i in range(N):
        # 이미 카메라를 만났다면 무시
        if recorded[i]:
            continue
        answer += 1
        # 카메라를 진출 지점에 설치
        camera = routes[i][EXIT]

        # 설치된 카메라를 만난 자동차를 탐색
        for j in range(i, N):
            if routes[j][ENTER] <= camera <= routes[j][EXIT]:
                recorded[j] = True
    return answer


print(solution([[-20, 15], [-14, -5], [-18, -13], [-5, -3]]))
