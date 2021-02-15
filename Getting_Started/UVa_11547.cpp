// https://onlinejudge.org/external/115/11547.pdf

#include <bits/stdc++.h>

using namespace std;

int solution(int n)
{
    int x = ((((n * 567) / 9) + 7492) * 235) / 47 - 498;
    if (x < 0)
        x = -x;
    return x / 10 % 10;
}

int main()
{
    int t;
    int n;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%d\n", solution(n));
    }
    return 0;
}