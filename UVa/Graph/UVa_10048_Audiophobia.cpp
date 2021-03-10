// https://onlinejudge.org/external/100/10048.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

int V, E, Q;
int parent[101];

int find(int u)
{
    return parent[u] < 0 ? u : parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u != v)
    {
        int tmp = parent[u] + parent[v];
        if (-parent[u] < -parent[v])
        {
            parent[u] = v;
            parent[v] = tmp;
        }
        else
        {
            parent[v] = u;
            parent[u] = tmp;
        }
    }
}

int main()
{
    int tc = 0;
    int u, v, w;
    while (scanf("%d %d %d", &V, &E, &Q), V | E | Q)
    {
        vector<tuple<int, int, int>> edges;
        vector<vector<pair<int, int>>> AL(V + 1);

        REP(i, E)
        {
            scanf("%d %d %d", &u, &v, &w);
            edges.push_back({w, u, v});
        }
        sort(edges.begin(), edges.end());

        if (tc)
            puts("");
        printf("Case #%d\n", ++tc);
        REP(i, Q)
        {
            scanf("%d %d", &u, &v);
            RESET(parent, -1);
            int j;
            for (j = 0; j < E; ++j)
            {
                auto [w, a, b] = edges[j];
                merge(a, b);
                if (find(u) == find(v))
                    break;
            }
            if (j >= E)
                printf("no path\n");
            else
                printf("%d\n", get<0>(edges[j]));
        }
    }

    return 0;
}