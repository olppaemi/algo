// https://onlinejudge.org/external/104/10496.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))
#define INF 1000000000

#define LSOne(x) ((x) & -(x))

typedef pair<int, int> ii;
typedef vector<ii> vii;

#define MAXB 11
int dist[MAXB][MAXB];
int distance(ii a, ii b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int memo[MAXB][(1 << MAXB)];
int dp(int u, int mask)
{
    if (mask == 0)
        return dist[u][0];
    int &ans = memo[u][mask];
    if (ans != -1)
        return ans;
    ans = INF;
    int m = mask;
    while (m)
    {
        int two_pow_v = LSOne(m);
        int v = __builtin_ctz(two_pow_v);
        ans = min(ans, dist[u][v] + dp(v, mask ^ two_pow_v));
        m -= two_pow_v;
    }
    return ans;
}

int main()
{
    int n, m;
    int tc, x, y, num;

    scanf("%d", &tc);
    while (tc--)
    {
        vii beepers;
        RESET(memo, -1);

        scanf("%d %d", &n, &m);
        scanf("%d %d", &x, &y);
        beepers.push_back({x, y});
        scanf("%d", &num);
        FOR(i, 1, num + 1)
        {
            scanf("%d %d", &x, &y);
            if (x >= 0 and x <= n and y >= 0 and y <= m)
                beepers.push_back({x, y});
        }
        sort(beepers.begin(), beepers.end());
        int sz = unique(beepers.begin(), beepers.end()) - beepers.begin();

        REP(i, sz)
        {
            REP(j, i)
            {
                int d = distance(beepers[i], beepers[j]);
                dist[i][j] = d;
                dist[j][i] = d;
            }
        }

        printf("The shortest path has length %d\n", dp(0, (1 << sz) - 1));
    }

    return 0;
}