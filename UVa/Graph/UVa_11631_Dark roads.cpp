#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))
#define MAXM 200000

int parent[MAXM];
int m, n;

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

int kruskal()
{
    vector<tuple<int, int, int>> AL;
    int u, v, w;
    int total = 0;
    RESET(parent, -1);

    REP(i, n)
    {
        scanf("%d %d %d", &u, &v, &w);
        AL.push_back({w, u, v});
        total += w;
    }
    sort(AL.begin(), AL.end());

    int mst_cost = 0, num_taken = 0;
    for (auto &[w, u, v] : AL)
    {
        if (find(u) == find(v))
            continue;
        mst_cost += w;
        merge(u, v);
        ++num_taken;
        if (num_taken == m - 1)
            break;
    }
    return total - mst_cost;
}
//------------------------------------------------------------
vector<vector<pair<int, int>>> AL;
vector<int> taken;
priority_queue<pair<int, int>> pq;
void process(int u)
{
    taken[u] = 1;
    for (auto &[v, w] : AL[u])
    {
        if (!taken[v])
            pq.push({-w, -v});
    }
}

int prim()
{
    int u, v, w;
    int total = 0;

    AL.assign(m, vector<pair<int, int>>());
    taken.assign(m, 0);
    while (!pq.empty())
        pq.pop();

    REP(i, n)
    {
        scanf("%d %d %d", &u, &v, &w);
        AL[u].push_back({v, w});
        AL[v].push_back({u, w});
        total += w;
    }
    process(0);
    int mst_cost = 0, num_taken = 0;
    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();
        w = -w, u = -u;
        if (taken[u])
            continue;
        mst_cost += w;
        process(u);
        ++num_taken;
        if (num_taken == m - 1)
            break;
    }
    return total - mst_cost;
}

int main()
{
    while (scanf("%d %d", &m, &n), m | n)
    {
        printf("%d\n", kruskal());
        // printf("%d\n", prim());
    }

    return 0;
}