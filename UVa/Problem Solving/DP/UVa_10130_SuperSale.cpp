// https://onlinejudge.org/external/101/10130.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

const int MAXN = 1001;
const int MAXW = 31;
struct item
{
    int weight, price;
};
int n;
item items[MAXN];

int memo[MAXN][MAXW];
int dp(int i, int remW)
{
    if (i == n or remW == 0)
        return 0;
    int &ans = memo[i][remW];
    if (ans != -1)
        return ans;
    if (items[i].weight > remW)
        return ans = dp(i + 1, remW);
    return ans = max(dp(i + 1, remW), items[i].price + dp(i + 1, remW - items[i].weight));
}

int main()
{
    int tc, g;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d", &n);
        REP(i, n)
        {
            scanf("%d %d", &items[i].price, &items[i].weight);
        }

        int sum = 0, w;
        scanf("%d", &g);
        REP(i, g)
        {
            RESET(memo, -1);
            scanf("%d", &w);
            sum += dp(0, w);
        }
        printf("%d\n", sum);
    }

    return 0;
}