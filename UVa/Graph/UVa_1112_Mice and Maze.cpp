// https://onlinejudge.org/external/11/1112.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)
#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AL;

int main()
{
    int tc;
    int n, e, t, m;
    int u, v, w;

    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d %d %d %d", &n, &e, &t, &m);
        AL.assign(n + 1, vii());
        REP(i, m)
        {
            scanf("%d %d %d", &u, &v, &w);
            AL[v].push_back({u, w});
        }

        vi dist(n + 1, INF);
        dist[e] = 0;
        priority_queue<ii> pq;
        pq.push({0, e});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            d = -d;
            if (d > dist[u])
                continue;
            for (auto &[v, w] : AL[u])
            {
                if (dist[u] + w >= dist[v])
                    continue;
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
        int ans = 0;
        REPN(i, n)
        {
            if (dist[i] <= t)
                ++ans;
        }

        printf("%d\n", ans);
        if (tc)
            puts("");
    }

    return 0;
}