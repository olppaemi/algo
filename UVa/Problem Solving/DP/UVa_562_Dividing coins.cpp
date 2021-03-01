// https://onlinejudge.org/external/5/562.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

int n, coins[100];
int dp[100][500 * 100 + 1];

int bag(int idx, int rem_v)
{
    if (idx == n or rem_v == 0)
        return 0;
    int &ans = dp[idx][rem_v];
    if (ans != -1)
        return ans;
    if (coins[idx] > rem_v)
        return ans = bag(idx + 1, rem_v);
    return ans = max(bag(idx + 1, rem_v), coins[idx] + bag(idx + 1, rem_v - coins[idx]));
}

int main()
{
    int tc;

    scanf("%d", &tc);
    while (tc--)
    {
        RESET(dp, -1);
        scanf("%d", &n);

        int total = 0;
        REP(i, n)
        {
            scanf("%d", &coins[i]);
            total += coins[i];
        }
        int x = bag(0, total / 2), y = total - x;
        printf("%d\n", abs(x - y));
    }

    return 0;
}