// https://www.acmicpc.net/problem/3665

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)

int main()
{
    int tc, n, m;

    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d", &n);

        vector<bool> adj_matrix[n + 1];
        int indegree[n + 1] = {};
        int rank[n];

        FOR(i, 1, n + 1)
        {
            adj_matrix[i].assign(n + 1, false);
        }

        REP(i, n)
        {
            scanf("%d", &rank[i]);
        }

        REP(i, n)
        {
            FOR(j, i + 1, n)
            {
                adj_matrix[rank[i]][rank[j]] = true;
                ++indegree[rank[j]];
            }
        }

        scanf("%d", &m);
        int u, v;
        REP(i, m)
        {
            scanf("%d %d", &u, &v);
            if (adj_matrix[u][v])
            {
                adj_matrix[u][v] = false;
                adj_matrix[v][u] = true;
                ++indegree[u];
                --indegree[v];
            }
            else
            {
                adj_matrix[u][v] = true;
                adj_matrix[v][u] = false;
                --indegree[u];
                ++indegree[v];
            }
        }

        queue<int> q;
        vector<int> ans;
        bool certain = true, cycle = false;

        FOR(i, 1, n + 1)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        REP(i, n)
        {
            if (q.empty())
            {
                cycle = true;
                break;
            }
            if (q.size() > 2)
            {
                certain = false;
                break;
            }

            int u = q.front();
            q.pop();
            ans.push_back(u);
            FOR(v, 1, n + 1)
            {
                if (adj_matrix[u][v])
                {
                    --indegree[v];
                    if (indegree[v] == 0)
                        q.push(v);
                }
            }
        }
        if (!certain)
            printf("?\n");
        else if (cycle)
            printf("IMPOSSIBLE\n");
        else
        {
            for (auto &x : ans)
                printf("%d ", x);
            puts("");
        }
    }
    return 0;
}