# https://onlinejudge.org/external/115/11565.pdf

def solution(a, b, c):
    for x in range(-22, 23):
        if x * x <= c:
            for y in range(-100, 101):
                if y != x and x * x + y * y <= c:
                    for z in range(-100, 100):
                        if z != x and z != y and x+y+z == a and x*y*z == b and x*x + y*y + z*z == c:
                            return x, y, z
    return 0, 0, 0


tc = int(input())
for i in range(tc):
    a, b, c = map(int, input().split())
    x, y, z = solution(a, b, c)
    if x and y and z:
        print(x, y, z)
    else:
        print("No solution.")
