// https://onlinejudge.org/external/117/11749.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

int parent[501];

int find(int u)
{
    if (parent[u] >= 0)
        return parent[u] = find(parent[u]);
    return u;
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
    int n, m;

    while (scanf("%d %d", &n, &m), n)
    {
        RESET(parent, -1);
        vector<tuple<int, int, int>> roads(m, {0, 0, 0}), tmp;
        int max_profit = INT32_MIN;
        int u, v, p;
        REP(i, m)
        {
            scanf("%d %d %d", &u, &v, &p);
            roads[i] = {u, v, p};
            if (p > max_profit)
                max_profit = p;
        }

        REP(i, m)
        {
            if (get<2>(roads[i]) == max_profit)
                tmp.push_back(roads[i]);
        }
        roads = tmp;

        for (auto &[u, v, p] : roads)
        {
            if (find(u) != find(v))
            {
                merge(u, v);
            }
        }

        int ans = 1;
        FOR(i, 1, n + 1)
        {
            if (-parent[i] > ans)
                ans = -parent[i];
        }
        printf("%d\n", ans);
    }

    return 0;
}