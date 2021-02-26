# https://onlinejudge.org/external/109/10925.pdf

import sys
inputs = sys.stdin.read().splitlines()
caseNo = 1
ln = 0
while True:
    N, F = map(int, inputs[ln].split())
    ln += 1
    if not N and not F:
        break
    sum = 0
    for _ in range(N):
        sum += int(inputs[ln])
        ln += 1

    print(f"Bill #{caseNo} costs {sum}: each friend should pay {sum // F}\n")
    caseNo += 1
