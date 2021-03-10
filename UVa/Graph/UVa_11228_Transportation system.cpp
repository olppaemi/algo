// https://onlinejudge.org/external/112/11228.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

vector<tuple<double, int, int>> short_edges, long_edges;
vector<pair<int, int>> coordinates;
int n, r;
int parent[500000];

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

double distance(pair<int, int> a, pair<int, int> b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{
    int tc, x, y;

    scanf("%d", &tc);
    REPN(case_num, tc)
    {
        RESET(parent, -1), coordinates.clear(), short_edges.clear(), long_edges.clear();

        scanf("%d %d", &n, &r);
        REP(i, n)
        {
            scanf("%d %d", &x, &y);
            coordinates.push_back({x, y});
        }
        REP(i, n)
        {
            FOR(j, i + 1, n)
            {
                double dist = distance(coordinates[i], coordinates[j]);
                if (dist <= r)
                    short_edges.push_back({dist, i, j});
                else
                    long_edges.push_back({dist, i, j});
            }
        }
        sort(short_edges.begin(), short_edges.end());
        sort(long_edges.begin(), long_edges.end());
        double road = 0, railroad = 0;
        int cities = n;

        for (auto &[w, u, v] : short_edges)
        {
            if (find(u) != find(v))
            {
                merge(u, v);
                road += w;
                --cities;
            }
        }

        for (auto &[w, u, v] : long_edges)
        {
            if (find(u) != find(v))
            {
                merge(u, v);
                railroad += w;
            }
        }

        printf("Case #%d: %d %d %d\n", case_num, cities, (int)round(road), (int)round(railroad));
    }

    return 0;
}