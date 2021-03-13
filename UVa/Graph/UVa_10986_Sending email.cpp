// https://onlinejudge.org/external/109/10986.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)
#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m, s, t;
vector<vii> AL;

int main()
{
    int tc;
    int u, v, w;
    scanf("%d", &tc);
    REPN(case_number, tc)
    {
        scanf("%d %d %d %d", &n, &m, &s, &t);
        AL.assign(n, vii());
        REP(i, m)
        {
            scanf("%d %d %d", &u, &v, &w);
            AL[u].push_back({v, w});
            AL[v].push_back({u, w});
        }
        priority_queue<ii, vii, greater<ii>> pq;
        vi dist(n, INF);
        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            if (w > dist[u])
                continue;
            for (auto &[v, w] : AL[u])
            {
                if (dist[u] + w >= dist[v])
                    continue;
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
        printf("Case #%d: ", case_number);
        if (dist[t] == INF)
            printf("unreachable\n");
        else
            printf("%d\n", dist[t]);
    }

    return 0;
}