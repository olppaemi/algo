// https://onlinejudge.org/external/110/11044.pdf

#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m)
{
    return (n / 3) * (m / 3);
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