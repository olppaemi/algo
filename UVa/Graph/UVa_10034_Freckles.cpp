// https://onlinejudge.org/external/100/10034.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

double X[100], Y[100];
int parent[100];
vector<tuple<double, int, int>> edges;

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
            parent[v] += tmp;
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
    int tc, n;

    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d", &n);
        REP(i, n)
        {
            scanf("%lf %lf", &X[i], &Y[i]);
        }

        edges.clear();
        REP(i, n)
        {
            FOR(j, i + 1, n)
            {
                double dist = hypot(X[i] - X[j], Y[i] - Y[j]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        RESET(parent, -1);
        int num_taken = 0;
        double mst_cost = 0;
        for (auto &[w, u, v] : edges)
        {
            if (find(u) != find(v))
            {
                mst_cost += w;
                merge(u, v);
                if (++num_taken == n - 1)
                    break;
            }
        }
        printf("%.2f\n", mst_cost);
        if (tc)
            puts("");
    }

    return 0;
}