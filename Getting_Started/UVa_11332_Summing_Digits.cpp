// https://onlinejudge.org/external/113/11332.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INF 1000000000
typedef vector<int> vi;
typedef tuple<int, int> ii;

int digit_sum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int solution(int n)
{
    while (n >= 10)
        n = digit_sum(n);
    return n;
}

int main()
{
    int n;
    while (scanf("%d", &n) == 1, (n))
    {
        printf("%d\n", solution(n));
    }
    return 0;
}