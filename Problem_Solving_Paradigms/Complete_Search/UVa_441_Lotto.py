# https://onlinejudge.org/external/4/441.pdf

def solution(numbers):
    from itertools import combinations

    for comb in combinations(numbers, 6):
        print(comb[0], comb[1], comb[2], comb[3], comb[4], comb[5])


count = 0
while True:
    numbers = list(map(int, input().split()))
    if numbers[0] == 0:
        break
    if count:
        print()
    solution(numbers[1:])
    count += 1
