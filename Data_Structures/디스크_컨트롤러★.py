from heapq import heappop, heappush
from collections import deque


def solution(jobs):
    N = len(jobs)
    jobs = deque(sorted(jobs))
    jobs_queue = []
    jobs_done, cur_time,  = 0, 0
    answer = 0

    while jobs_done < N:
        if not jobs_queue:
            request_time, process_time = jobs.popleft()
            cur_time = request_time + process_time
            answer += process_time
        else:
            process_time, request_time = heappop(jobs_queue)
            cur_time += process_time
            answer += cur_time - request_time

        jobs_done += 1
        while jobs and jobs[0][0] <= cur_time:
            heappush(jobs_queue, jobs.popleft()[::-1])

    return answer // N


def solution2(jobs):
    jobs.sort()
    answer = []
    time = 0

    while jobs:
        if time < jobs[0][0]:
            time = jobs[0][0]

        mn, idx = jobs[0][1], 0
        for j in range(1, len(jobs)):
            if jobs[j][0] < time and jobs[j][1] < mn:
                mn = jobs[j][1]
                idx = j
        time += jobs[idx][1]
        answer.append((jobs[idx][0], time))
        del jobs[idx]
    return sum([y - x for x, y in answer]) // len(answer)


print(solution([[0, 3], [1, 9], [2, 6]]))
