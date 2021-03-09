// https://onlinejudge.org/external/118/11838.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)

int n, m;
vector<vector<int>> adj_list;
vector<int> dfs_num, dfs_low, visited;
int dfs_counter, num_scc;
stack<int> st;

void dfs(int u)
{
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    visited[u] = 1;
    st.push(u);

    for (auto &v : adj_list[u])
    {
        if (dfs_num[v] == -1)
            dfs(v);
        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_num[u] == dfs_low[u])
    {
        ++num_scc;
        while (1)
        {
            int v = st.top();
            st.pop();
            visited[v] = 0;
            if (u == v)
                break;
        }
    }
}

int main()
{    
    int v, w, p;
    while (scanf("%d %d", &n, &m), n || m)
    {
        adj_list.assign(n + 1, vector<int>());
        num_scc = dfs_counter = 0;
        dfs_num.assign(n + 1, -1);
        dfs_low.assign(n + 1, 0);
        visited.assign(n + 1, 0);
        while (!st.empty())
            st.pop();

        REP(i, m)
        {
            scanf("%d %d %d", &v, &w, &p);
            if (p == 1)
            {
                adj_list[v].push_back(w);
            }
            else if (p == 2)
            {
                adj_list[v].push_back(w);
                adj_list[w].push_back(v);
            }
        }

        REPN(i, n)
        {
            if (dfs_num[i] == -1)
                dfs(i);
        }

        if (num_scc == 1)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}