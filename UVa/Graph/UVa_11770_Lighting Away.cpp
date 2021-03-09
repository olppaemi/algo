// https://onlinejudge.org/external/117/11770.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)
#define MAXN 10001

vector<int> adj_list[MAXN];
vector<int> ts;
bitset<MAXN> visited;

void dfs(int u, int flag)
{
    visited[u] = 1;
    for (auto &v : adj_list[u])
    {
        if (!visited[v])
            dfs(v, flag);
    }
    if (flag)
        ts.push_back(u);
}

int main()
{
    int tc;
    int n, m;
    int u, v;

    scanf("%d", &tc);
    REPN(case_number, tc)
    {
        scanf("%d %d", &n, &m);

        ts.clear();
        visited.reset();
        REPN(i, n)
        {
            adj_list[i].clear();
        }

        REP(i, m)
        {
            scanf("%d %d", &u, &v);
            adj_list[u].push_back(v);
        }

        REPN(i, n)
        {
            if (!visited[i])
                dfs(i, 1);
        }

        visited.reset();
        int ans = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int u = ts[i];
            if (!visited[u])
            {
                dfs(u, 0);
                ++ans;
            }
        }
        printf("Case %d: %d\n", case_number, ans);
    }
    return 0;
}