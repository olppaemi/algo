// https://onlinejudge.org/external/105/10505.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CONTAINS(v, x) (find(ALL(v), x) != v.end())

int n;
vector<int> adj_list[201];
int color[201];

int bfs(int s)
{
    bool is_bipartite = true;
    int white = 0, black = 0;
    queue<int> q;
    q.push(s);
    color[s] = 0;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        color[now] == 0 ? ++white : ++black;

        for (auto &nxt : adj_list[now])
        {
            if (color[nxt] == -1)
            {
                color[nxt] = 1 - color[now];
                q.push(nxt);
            }
            else if (color[now] == color[nxt])
                is_bipartite = false;
        }
    }

    return is_bipartite ? max(white, black) : 0;
}

int main()
{
    int tc, p, v;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d", &n);
        RESET(color, -1);
        REPN(i, n)
        {
            adj_list[i].clear();
        }

        REPN(u, n)
        {
            scanf("%d", &p);
            REP(j, p)
            {
                scanf("%d", &v);
                if (v <= n)
                {
                    if (!CONTAINS(adj_list[u], v))
                        adj_list[u].push_back(v);
                    if (!CONTAINS(adj_list[v], u))
                        adj_list[v].push_back(u);
                }
            }
        }

        int ans = 0;
        REPN(i, n)
        {
            if (color[i] == -1)
                ans += bfs(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}