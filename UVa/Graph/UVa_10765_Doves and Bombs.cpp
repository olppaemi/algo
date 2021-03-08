// https://onlinejudge.org/external/107/10765.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define UNVISITED -1

struct node
{
    int id, pigeon_value;

    bool operator<(const node &n) const
    {
        return pigeon_value == n.pigeon_value ? id > n.id : pigeon_value < n.pigeon_value;
    }
};

int n, m;
vector<vector<int>> adj_list;

vector<int> dfs_num, dfs_low, pigeons;
int dfs_root, root_child, dfs_counter;

void dfs_visit(int parent, int u)
{
    dfs_low[u] = dfs_num[u] = dfs_counter++;
    pigeons[u] = 1;
    int root_children = 0;

    for (auto &v : adj_list[u])
    {
        if (dfs_num[v] == UNVISITED)
        {
            if (parent == -1)
                ++root_children;

            dfs_visit(u, v);

            if (dfs_low[v] >= dfs_num[u])
            {
                if (parent != -1 or root_children >= 2)
                    ++pigeons[u];
            }

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
    dfs_num.assign(n, UNVISITED);
    dfs_low.assign(n, 0);
    pigeons.assign(n, 0);
    REP(i, n)
    {
        if (dfs_num[i] == UNVISITED)
            dfs_visit(-1, i);
    }
}

int main()
{
    int u, v;
    while (scanf("%d %d", &n, &m), n || m)
    {

        adj_list.assign(n, vector<int>());
        while (scanf("%d %d", &u, &v), u != -1 and v != -1)
        {
            if (u < n and v < n)
            {
                adj_list[u].push_back(v);
                adj_list[v].push_back(u);
            }
        }

        dfs();

        priority_queue<node> q;
        REP(i, n)
        {
            q.push({i, pigeons[i]});
        }

        REP(i, m)
        {
            node x = q.top();
            q.pop();
            printf("%d %d\n", x.id, x.pigeon_value);
        }
        puts("");
    }

    return 0;
}