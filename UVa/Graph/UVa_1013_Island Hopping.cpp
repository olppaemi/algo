// https://onlinejudge.org/external/10/1013.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

int V;
int X[50], Y[50], M[50];
int parent[50];
int weight[50];
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
            weight[v] += weight[u];
        }
        else
        {
            parent[v] = u;
            parent[u] = tmp;
            weight[u] += weight[v];
        }
    }
}

int main()
{
    int gn = 0;
    while (scanf("%d", &V), V)
    {
        int sum_m = 0;
        double sum_tm = 0;
        REP(i, V)
        {
            scanf("%d %d %d", &X[i], &Y[i], &M[i]);
            sum_m += M[i];
            weight[i] = M[i];
        }

        edges.clear();
        REP(i, V)
        {
            FOR(j, i + 1, V)
            {
                double dist = hypot(X[i] - X[j], Y[i] - Y[j]);
                edges.push_back({dist, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        RESET(parent, -1);
        for (auto &[t, u, v] : edges)
        {
            u = find(u), v = find(v);
            if (u != v)
            {
                if (u == find(0))
                    sum_tm += t * weight[v];
                else if (v == find(0))
                    sum_tm += t * weight[u];
                merge(u, v);
            }
        }
        printf("Island Group: %d Average %.2f\n\n", ++gn, sum_tm / (double)sum_m);
    }

    return 0;
}