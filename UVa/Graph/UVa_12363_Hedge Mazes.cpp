// https://onlinejudge.org/external/123/12363.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)

int r, c, q;
vector<vector<int>> adj_list;

vector<int> dfs_num, dfs_low, parent;
int dfs_counter;

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

void dfs_visit(int parent, int u)
{
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    for (auto &v : adj_list[u])
    {
        if (dfs_num[v] == -1)
        {
            dfs_visit(u, v);
            if (dfs_low[v] > dfs_num[u])
                merge(u, v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != parent)
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

void dfs()
{
    dfs_counter = 0;
    dfs_num.assign(r + 1, -1);
    dfs_low.assign(r + 1, 0);
    parent.assign(r + 1, -1);
    REPN(i, r)
    {
        if (dfs_num[i] == -1)
            dfs_visit(-1, i);
    }
}

int main()
{
    int u, v;
    while (scanf("%d %d %d", &r, &c, &q), r || c || q)
    {
        adj_list.assign(r + 1, vector<int>());
        REP(i, c)
        {
            scanf("%d %d", &u, &v);
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        dfs();

        REP(i, q)
        {
            scanf("%d %d", &u, &v);
            printf("%c\n", (find(u) == find(v) ? 'Y' : 'N'));
        }
        printf("-\n");
    }

    return 0;
}
