# https://programmers.co.kr/learn/courses/30/lessons/17678

def solution(n, t, m, timetable):
    timetable = [int(time[:2]) * 60 + int(time[3:]) for time in timetable]
    timetable.sort()
    last_time = 540 + (n - 1) * t

    for i in range(n):
        if len(timetable) < m:
            return f"{last_time // 60:02}:{last_time % 60:02}"
        if i == n - 1:
            last_bus = [time for time in timetable if time <= last_time]
            # 마지막 버스의 정원을 초과하는 사람이 기다리고 있다면,
            # 마지막에 타게 되는 사람보다 1분 먼저 나와서 기다려야 한다.
            if len(last_bus) >= m:
                time = timetable[m - 1] - 1
                return f"{time // 60:02}:{time % 60:02}"
            # 그렇지 않다면, 버스 도착 시간에 도착하면 된다.
            else:
                return f"{last_time // 60:02}:{last_time % 60:02}"
        for j in range(m - 1, -1, -1):
            bus_arrive = 540 + i * t
            if timetable[j] <= bus_arrive:
                del timetable[j]


print(solution(1, 1, 5, ["08:00", "08:01", "08:02", "08:03"]))
print(solution(2, 10, 2, ["09:10", "09:09", "08:00"]))
print(solution(2, 1, 2, ["09:00", "09:00", "09:00", "09:00"]))
print(solution(10, 60, 10, ["17:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59",
                            "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"]))
