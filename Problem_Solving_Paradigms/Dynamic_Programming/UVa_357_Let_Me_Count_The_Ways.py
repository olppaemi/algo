# https://onlinejudge.org/external/3/357.pdf

coins = [1, 5, 10, 25, 50]

ways = [1] + [0] * 30000
for c in coins:
    for i in range(c, 30000 + 1):
        ways[i] += ways[i - c]

while True:
    try:
        money = int(input())
        answer = ways[money]
        if answer == 1:
            print(f"There is only 1 way to produce {money} cents change.")
        else:
            print(f"There are {answer} ways to produce {money} cents change.")
    except EOFError:
        break
