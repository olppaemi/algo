// https://onlinejudge.org/external/100/10071.pdf

#include <bits/stdc++.h>

using namespace std;

int solution(int v, int t)
{
    return 2 * v * t;
}

int main()
{
    int v, t;
    while (scanf("%d %d", &v, &t) == 2)
    {
        printf("%d\n", solution(v, t));
    }
    return 0;
}