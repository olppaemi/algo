# https://onlinejudge.org/external/5/507.pdf

def solution(nice):
    s, mx = -1, 0
    start, final_start, final_end = -1, -1, -1

    for i in range(1, len(nice)):
        if s >= 0:
            s += nice[i]
        else:  # if s < 0, reset
            s = nice[i]
            start = i

        if s > mx or (s == mx and i + 1 - start > final_end - final_start):
            mx = s
            final_start = start
            final_end = i + 1

    return (final_start, final_end) if mx > 0 else (-1, -1)


routes = int(input())
for i in range(1, routes + 1):
    stops = int(input())
    nice = [0]
    for _ in range(stops - 1):
        nice.append(int(input()))
    ans = solution(nice)
    if ans[0] == -1:
        print(f"Route {i} has no nice parts")
    else:
        print(
            f"The nicest part of route {i} is between stops {ans[0]} and {ans[1]}")
