# https://onlinejudge.org/external/119/11935.pdf

import sys
import re
sys.stdin = open("input.txt", "r")
sys.stdout = open('output.txt', 'w')


def solution(events):

    def can(fuel):
        remain = fuel
        consume = events[0][2] / 100
        leak = 0
        for i in range(1, len(events)):
            remain -= (consume + leak) * (events[i][0] - events[i-1][0])
            if remain < 0:
                return False
            if events[i][1] == "Fuel consumption":
                consume = events[i][2] / 100
            elif events[i][1] == "Leak":
                leak += 1
            elif events[i][1] == "Gas station":
                remain = fuel
            elif events[i][1] == "Mechanic":
                leak = 0
        return True

    answer = 0.0
    start, end = 0.0, 10000.0
    for i in range(50):  # log_2 ((10000.0 - 0.0) / 1e-9) ~= 43
        mid = (start + end) / 2
        if (can(mid)):
            answer = mid
            end = mid
        else:
            start = mid

    return f"{answer:.3f}"


p = re.compile(r"(\d+)([a-zA-Z ]+)(\d*)")
while True:
    ev = input()
    if ev == "0 Fuel consumption 0":
        break
    dist, op, fuel = p.search(ev).groups()
    events = [(int(dist), op.strip(), int(fuel))]
    while not ("Goal" in ev):
        ev = input()
        dist, op, fuel = p.search(ev).groups()
        if not fuel:
            events.append((int(dist), op.strip()))
        else:
            events.append((int(dist), op.strip(), int(fuel)))
    print(solution(events))
