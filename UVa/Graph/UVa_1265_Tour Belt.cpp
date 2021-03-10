// https://onlinejudge.org/external/12/1265.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))
#define INF 1000000000

typedef tuple<int, int, int> iii;
typedef vector<iii> viii;

int parent[5001];
int n, m;
viii edges;

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

int judge(int u)
{
    int min_e = INF, max_e = 0;
    for (auto &[w, x, y] : edges)
    {
        x = find(x), y = find(y);
        if (x == u and y == u)
            min_e = min(min_e, w);
        else if (!(x != u and y != u))
            max_e = max(max_e, w);
    }
    if (min_e <= max_e)
        return 0;

    return -parent[u];
}

int main()
{
    int tc;
    int u, v, w;

    scanf("%d", &tc);
    while (tc--)
    {
        RESET(parent, -1);
        edges.clear();

        scanf("%d %d", &n, &m);
        REP(i, m)
        {
            scanf("%d %d %d", &u, &v, &w);
            edges.push_back({w, u, v});
        }
        sort(edges.begin(), edges.end(), greater<iii>());
        int ans = 0, num_taken = 0;

        for (auto &[w, u, v] : edges)
        {
            if (find(u) != find(v))
            {
                merge(u, v);
                ans += judge(find(u));
                ++num_taken;
            }
            if (num_taken == n - 1)
                break;
        }
        printf("%d\n", ans);
    }

    return 0;
}