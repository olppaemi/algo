// https://onlinejudge.org/external/114/11450.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))
#define INF 1000000000

int M, C;
int price[20][20];
int num[20];

int memo[20][201];
int dp(int g, int b)
{
    if (b < 0)
        return -INF;
    if (g == C)
        return M - b;
    int &ans = memo[g][b];
    if (ans != -1)
        return ans;

    REP(i, num[g])
    {
        ans = max(ans, dp(g + 1, b - price[g][i]));
    }
    return ans;
}

int bdp()
{
    REP(i, num[0])
    {
        if (M - price[0][i] >= 0)
            memo[0][M - price[0][i]] = 1;
    }

    FOR(g, 1, C)
    {
        REP(b, M)
        {
            if (memo[g - 1][b])
                REP(i, num[g])
                {
                    if (b - price[g][i] >= 0)
                        memo[g][b - price[g][i]] = 1;
                }
        }
    }
    int b;
    for (b = 0; b <= M and !memo[C - 1][b]; ++b)
        ;
    return M - b;
}

int solve()
{
    RESET(memo, 0);
    return bdp();
}

int main()
{
    int tc;

    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d %d", &M, &C);
        REP(i, C)
        {
            scanf("%d", &num[i]);
            REP(j, num[i])
            {
                scanf("%d", &price[i][j]);
            }
        }
        int ans = solve();
        if (ans < 0)
            printf("no solution\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}