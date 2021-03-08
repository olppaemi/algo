// https://onlinejudge.org/external/3/315.pdf

#include <bits/stdc++.h>
using namespace std;

#define REPN(i, n) for (int i = 1; i <= n; ++i)
#define UNVISITED -1

int n;
vector<vector<int>> adj_list;

vector<int> dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfs_root, root_child, dfs_counter;

void dfs(int u)
{
    dfs_low[u] = dfs_num[u] = dfs_counter++;

    for (auto &v : adj_list[u])
    {
        if (dfs_num[v] == UNVISITED)
        {
            dfs_parent[v] = u;
            if (dfs_root == u)
                ++root_child;

            dfs(v);

            if (dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = 1;

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u]) // if a non-trivial cycle
        {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main()
{
    string line;
    int u, v;

    while (cin >> n, n)
    {
        adj_list.assign(n + 1, vector<int>());
        dfs_num.assign(n + 1, UNVISITED);
        dfs_low.assign(n + 1, 0);
        dfs_parent.assign(n + 1, 0);
        articulation_vertex.assign(n + 1, 0);

        cin.ignore();
        while (getline(cin, line), line != "0")
        {
            istringstream iss(line);

            iss >> u;
            while (iss >> v)
            {
                adj_list[u].push_back(v);
                adj_list[v].push_back(u);
            }
        }

        REPN(i, n)
        {
            if (dfs_num[i] == UNVISITED)
            {
                dfs_root = i;
                root_child = 0;
                dfs(i);
                articulation_vertex[i] = (root_child > 1);
            }
        }

        cout << count(articulation_vertex.begin(), articulation_vertex.end(), 1) << '\n';
    }

    return 0;
}