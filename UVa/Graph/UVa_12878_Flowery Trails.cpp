#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<vii> AL;

vi dijkstra(int n, int s)
{
    vi dist(n, INF);
    dist[s] = 0;
    priority_queue<ii> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        d = -d;
        if (d > dist[u])
            continue;
        for (auto [v, w] : AL[u])
        {
            if (dist[u] + w >= dist[v])
                continue;
            dist[v] = dist[u] + w;
            pq.push({-dist[v], v});
        }
    }
    return dist;
}

int main()
{
    int p, t;
    int u, v, w;

    while (scanf("%d %d", &p, &t) != EOF)
    {
        AL.assign(p, vii());
        REP(i, t)
        {
            scanf("%d %d %d", &u, &v, &w);
            AL[u].push_back({v, w});
            AL[v].push_back({u, w});
        }

        vi dist1 = dijkstra(p, 0);
        vi dist2 = dijkstra(p, p - 1);
        int sp = dist1[p - 1], ans = 0;
        REP(u, p)
        {
            for (auto [v, w] : AL[u])
            {
                if (dist1[u] + w + dist2[v] == sp)
                    ans += w;
            }
        }
        printf("%d\n", ans * 2);
    }

    return 0;
}