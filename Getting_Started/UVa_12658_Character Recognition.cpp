// https://onlinejudge.org/external/126/12658.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INF 1000000000
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{
    int n;
    char a[4 * 13];

    scanf("%d", &n);
    scanf("%*s %*s %*s %s %*s", a);

    int x = 0;
    REP(i, n)
    {
        if (a[x + 1] == '*')
            printf("1");
        else if (a[x] == '*')
            printf("2");
        else
            printf("3");
        x += 4;
    }
    puts("");

    return 0;
}