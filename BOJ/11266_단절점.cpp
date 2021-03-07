// https://www.acmicpc.net/problem/11266

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)

typedef vector<int> vi;

enum
{
    UNVISITED = -1,
    VISITED = -2,
    EXPLORED = -3
};

vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfs_counter = 0, dfs_root, root_children;

vector<vi> adj_list;

void dfs(int u)
{
    dfs_low[u] = dfs_num[u] = dfs_counter++;
    for (auto &v : adj_list[u])
    {
        if (dfs_num[v] == UNVISITED)
        {
            dfs_parent[v] = u;
            if (u == dfs_root)
                ++root_children;

            dfs(v);

            if (dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = 1;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main()
{
    int n, e;
    scanf("%d %d", &n, &e);
    dfs_num.assign(n + 1, UNVISITED);
    dfs_low.assign(n + 1, 0);
    dfs_parent.assign(n + 1, 0);
    articulation_vertex.assign(n + 1, 0);
    adj_list.assign(n + 1, vector<int>());

    int x, y;
    REP(i, e)
    {
        scanf("%d %d", &x, &y);
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }

    FOR(u, 1, n + 1)
    {
        if (dfs_num[u] == UNVISITED)
        {
            dfs_root = u;
            root_children = 0;
            dfs(u);
            articulation_vertex[dfs_root] = (root_children > 1);
        }
    }

    vi answer;
    FOR(u, 1, n + 1)
    {
        if (articulation_vertex[u])
            answer.push_back(u);
    }
    printf("%u\n", answer.size());
    for (auto &v : answer)
        printf("%d ", v);

    return 0;
}