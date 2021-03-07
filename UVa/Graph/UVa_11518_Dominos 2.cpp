// https://onlinejudge.org/external/115/11518.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

int n, m, l;

vector<int> adj_list[10001];
vector<bool> visited;
int ans;

void dfs(int u)
{
    visited[u] = true;
    ans++;
    for (auto &v : adj_list[u])
    {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    int tc, x, y;
    scanf("%d", &tc);

    while (tc--)
    {
        scanf("%d %d %d", &n, &m, &l);
        visited.assign(n + 1, false);
        ans = 0;

        REP(i, n + 1)
        {
            adj_list[i].clear();
        }

        REP(i, m)
        {
            scanf("%d %d", &x, &y);
            if (x != y)
                adj_list[x].push_back(y);
        }

        REP(i, l)
        {
            scanf("%d", &x);
            if (!visited[x])
                dfs(x);
        }
        printf("%d\n", ans);
    }
    return 0;
}