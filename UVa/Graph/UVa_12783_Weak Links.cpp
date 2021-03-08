// https://onlinejudge.org/external/127/12783.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

int n, m;
vector<vector<int>> adj_list;
vector<pair<int, int>> bridge;

vector<int> dfs_num, dfs_low;
int dfs_counter;

void dfs_visit(int prev, int u)
{
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    for (auto &v : adj_list[u])
    {
        if (dfs_num[v] == -1)
        {
            dfs_visit(u, v);

            if (dfs_low[v] == dfs_num[v])
            {
                bridge.push_back({min(u, v), max(u, v)});
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != prev)
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}
void dfs()
{
    dfs_counter = 0;
    dfs_num.assign(n, -1);
    dfs_low.assign(n, 0);
    REP(i, n)
    {
        if (dfs_num[i] == -1)
            dfs_visit(-1, i);
    }
}

int main()
{
    int u, v;
    while (scanf("%d %d", &n, &m), n || m)
    {
        adj_list.assign(n, vector<int>());
        bridge.clear();

        REP(i, m)
        {
            scanf("%d %d", &u, &v);
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        dfs();

        sort(bridge.begin(), bridge.end());
        printf("%d", bridge.size());
        for (auto &[u, v] : bridge)
            printf(" %d %d", u, v);
        puts("");
    }

    return 0;
}