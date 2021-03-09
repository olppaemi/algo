// https://onlinejudge.org/external/115/11504.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)

vector<vector<int>> adj_list;
vector<bool> visited;
vector<int> ts;

void toposort(int u)
{
    visited[u] = true;
    for (auto &v : adj_list[u])
    {
        if (!visited[v])
            toposort(v);
    }
    ts.push_back(u);
}

void dfs(int u)
{
    visited[u] = true;
    for (auto &v : adj_list[u])
    {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    int tc, u, v;
    int n, m;

    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d %d", &n, &m);
        adj_list.assign(n + 1, vector<int>());
        visited.assign(n + 1, false);
        ts.clear();

        REP(i, m)
        {
            scanf("%d %d", &u, &v);
            adj_list[u].push_back(v);
        }

        REPN(i, n)
        {
            if (!visited[i])
                toposort(i);
        }

        fill(visited.begin(), visited.end(), false);

        int knock = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int u = ts[i];
            if (!visited[u])
            {
                dfs(u);
                ++knock;
            }
        }
        printf("%d\n", knock);
    }
    return 0;
}