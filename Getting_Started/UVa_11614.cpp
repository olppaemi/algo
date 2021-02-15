// https://onlinejudge.org/external/116/11614.pdf

#include <bits/stdc++.h>

using namespace std;

long long solution(long long s)
{
    return (long long)floor((-1 + sqrt(1 + 8 * s)) / 2.0);
}

int main()
{
    int t;
    long long n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", solution(n));
    }
    return 0;
}