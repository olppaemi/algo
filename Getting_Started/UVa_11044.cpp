// https://onlinejudge.org/external/110/11044.pdf

#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m)
{
    if (n % 3)
        n -= (n % 3);
    if (m % 3)
        m -= (m % 3);

    return n * m / 9;
}

int main()
{
    int t;
    int n, m;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        printf("%d\n", solution(n, m));
    }
    return 0;
}