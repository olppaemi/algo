// https://onlinejudge.org/external/11/1193.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int n;
pair<double, double> island[1010];

int solve()
{
    sort(island, island + n);
    int cnt = 1, r = island[0].second;

    for (int i = 1; i < n; i++)
    {
        if (island[i].first > r)
        {
            r = island[i].second;
            cnt++;
        }
        else if (island[i].second < r)
        {
            r = island[i].second;
        }
    }
    return cnt;
}

int main()
{
    int tc = 1, d;
    int x, y;

    while (scanf("%d %d", &n, &d), n || d)
    {
        bool no_solution = false;
        REP(i, n)
        {
            scanf("%d %d", &x, &y);
            if (y > d)
            {
                no_solution = true;
                continue;
            }
            double dx = sqrt(d * d - y * y);
            island[i] = {x - dx, x + dx};
        }
        printf("Case %d: %d\n", tc++, no_solution ? -1 : solve());
    }

    return 0;
}