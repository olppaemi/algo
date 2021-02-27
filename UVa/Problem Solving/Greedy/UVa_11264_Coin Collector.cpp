// https://onlinejudge.org/external/112/11264.pdf

#include <cstdio>

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)

int main()
{
    int tc;
    int n, coins[1000];

    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d", &n);
        REP(i, n)
        {
            scanf("%d", &coins[i]);
        }

        int ans = 1, sum = coins[0];
        FOR(i, 1, n - 1)
        {
            if (coins[i] + sum < coins[i + 1])
            {
                sum += coins[i];
                ++ans;
            }
        }
        printf("%d\n", ans + 1);
    }

    return 0;
}