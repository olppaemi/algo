// https://onlinejudge.org/external/1/108.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)

#define MAX_N 101

// n <= 100
int maximum_sum(int n, int a[][MAX_N])
{
    REP(i, n)
    {
        REP(j, n)
        {
            scanf("%d", &a[i][j]);
            if (i > 0)
                a[i][j] += a[i - 1][j];
            if (j > 0)
                a[i][j] += a[i][j - 1];
            if (i > 0 and j > 0)
                a[i][j] -= a[i - 1][j - 1];
        }
    }

    int max_subrect = -100 * 100 * 127;
    REP(i, n)
    {
        REP(j, n)
        {
            FOR(k, i, n)
            {
                FOR(l, j, n)
                {
                    int subrect = a[k][l];
                    if (i > 0)
                        subrect -= a[i - 1][l];
                    if (j > 0)
                        subrect -= a[k][j - 1];
                    if (i > 0 and j > 0)
                        subrect += a[i - 1][j - 1];
                    max_subrect = max(max_subrect, subrect);
                }
            }
        }
    }
    return max_subrect;
}

// n <=450
int kadane2D(int n, int a[][MAX_N])
{
    REP(i, n)
    {
        REP(j, n)
        {
            scanf("%d", &a[i][j]);
            if (j > 0)
                a[i][j] += a[i][j - 1];
        }
    }

    int max_subrect = -100 * 100 * 127;
    REP(l, n)
    {
        FOR(r, l, n)
        {
            int subrect = 0;
            REP(row, n)
            {
                if (l > 0)
                    subrect += a[row][r] - a[row][l - 1];
                else
                    subrect += a[row][r];
                if (subrect < 0)
                    subrect = 0;
                max_subrect = max(max_subrect, subrect);
            }
        }
    }
    return max_subrect;
}

int main()
{
    int n;
    int a[MAX_N][MAX_N] = {};

    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", kadane2D(n, a));
    }

    return 0;
}