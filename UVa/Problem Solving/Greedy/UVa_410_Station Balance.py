# https://onlinejudge.org/external/4/410.pdf

def solution(c, s, masses):
    avg = sum(masses) / c
    imbalance = 0

    if s < 2 * c:
        masses += [0] * (2 * c - s)
    masses.sort()

    for i in range(c):
        imbalance += abs(masses[i] + masses[-1-i] - avg)
        print(f"{i:2}:", end="")
        if masses[i]:
            print(f" {masses[i]}", end="")
        if masses[-1-i]:
            print(f" {masses[-1-i]}", end="")
        print()
    print(f"IMBALANCE = {imbalance:.5f}\n")


count = 1
while True:
    try:
        c, s = map(int, input().split())
        masses = list(map(int, input().split()))
        print(f"Set #{count + 1}")
        solution(c, s, masses)
        count += 1
    except EOFError:
        break
