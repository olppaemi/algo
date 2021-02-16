// https://onlinejudge.org/external/100/10038.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INF 1000000000
typedef vector<int> vi;
typedef pair<int, int> ii;

int series(int n)
{
    return (n * (n + 1)) / 2;
}

int main()
{
    int n;
    int a[3000], b[3000];

    while (scanf("%d", &n) == 1)
    {
        string answer = "Jolly";
        int s = 0;
        REP(i, n)
        {
            scanf("%d", &a[i]);
        }
        REP(i, n - 1)
        {
            int x = abs(a[i + 1] - a[i]);
            if (x <= 0 or x > n - 1)
                break;
            s += x;
        }

        if (s != series(n - 1))
            answer = "Not jolly";
        printf("%s\n", answer.c_str());
    }

    return 0;
}