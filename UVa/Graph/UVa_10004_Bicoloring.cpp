// https://onlinejudge.org/external/100/10004.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define INF 1000000000

int main()
{
    int n, l, u, v;

    while (scanf("%d", &n), n)
    {
        vector<int> adj_list[n];
        scanf("%d", &l);
        REP(i, l)
        {
            scanf("%d %d", &u, &v);
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        int s = 0;
        queue<int> q;
        q.push(s);
        vector<int> color(n, INF);
        color[s] = 0;
        bool is_bipartite = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto &v : adj_list[u])
            {
                if (color[v] == INF)
                {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[u] == color[v])
                {
                    is_bipartite = false;
                    break;
                }
            }
        }
        if (is_bipartite)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }

    return 0;
}