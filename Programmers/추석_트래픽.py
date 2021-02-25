# https://programmers.co.kr/learn/courses/30/lessons/17676


def solution(lines):
    import re

    def to_milliseconds():
        p = re.compile(
            r"^2016-09-15 (\d\d):(\d\d):(\d\d).(\d\d\d) (\d+\.?\d*)s$")
        logs = []
        for l in lines:
            h, m, s, ms, pt = p.search(l).groups()
            end = int(ms) + int(s)*1000 + int(m)*1000*60 + int(h)*1000*60*60
            start = end - int(float(pt) * 1000) + 1
            logs.append((start, end))
        return logs

    logs = to_milliseconds()
    max_request = 0

    for i in range(len(logs)):
        for k in range(2):
            num_request = 0
            for j in range(len(logs)):
                start = logs[i][k]
                end = logs[i][k] + 999
                if logs[j][0] < start and logs[j][1] >= start:
                    num_request += 1
                elif logs[j][0] <= end and logs[j][1] > end:
                    num_request += 1
                elif logs[j][0] >= start and logs[j][1] <= end:
                    num_request += 1
            if num_request > max_request:
                max_request = num_request

    return max_request


print(solution(["2016-09-15 00:00:00.000 3s"]))
print(solution(["2016-09-15 20:59:57.421 0.351s",
                "2016-09-15 20:59:58.233 1.181s",
                "2016-09-15 20:59:58.299 0.8s",
                "2016-09-15 20:59:58.688 1.041s",
                "2016-09-15 20:59:59.591 1.412s",
                "2016-09-15 21:00:00.464 1.466s",
                "2016-09-15 21:00:00.741 1.581s",
                "2016-09-15 21:00:00.748 2.31s",
                "2016-09-15 21:00:00.966 0.381s",
                "2016-09-15 21:00:02.066 2.62s"]))
print(solution(["2016-09-15 01:00:04.002 2.0s",
                "2016-09-15 01:00:07.000 2s"]))
