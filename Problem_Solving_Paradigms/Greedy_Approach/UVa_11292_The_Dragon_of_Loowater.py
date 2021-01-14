# https://onlinejudge.org/external/112/11292.pdf

def solution(n, m, dragon, knight):
    dragon.sort()
    knight.sort()
    gold = d = k = 0
    while d < n and k < m:
        while dragon[d] > knight[k] and k < m:
            k += 1
        if k == m:
            break
        gold += knight[k]
        d += 1
        k += 1

    if d == n:
        return gold
    else:
        return "Loowater is doomed!"


while True:
    n, m = map(int, input().split())
    if not n and not m:
        break
    dragon = []
    knight = []
    for i in range(n):
        dragon.append(int(input()))
    for i in range(m):
        knight.append(int(input()))
    print(solution(n, m, dragon, knight))
