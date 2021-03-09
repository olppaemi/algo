// https://onlinejudge.org/external/117/11709.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define CONTAINS(v, x) (find(ALL(v), x) != v.end())

int n, m;
vector<int> adj_list[1000];
int dfs_num[1000], dfs_low[1000], visited[1000];
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    string name1, name2;
    while (cin >> n >> m, n | m)
    {
        map<string, int> name_to_id;
        vector<string> id_to_name;
        REP(i, n)
        {
            adj_list[i].clear();
        }
        RESET(dfs_num, -1);
        RESET(dfs_low, 0);
        RESET(visited, 0);
        num_scc = dfs_counter = 0;
        while (!st.empty())
            st.pop();

        cin.ignore();
        REP(i, n)
        {
            getline(cin, name1);
            id_to_name.push_back(name1);
            name_to_id[name1] = i;
        }
        REP(i, m)
        {
            getline(cin, name1);
            getline(cin, name2);
            int u = name_to_id[name1], v = name_to_id[name2];
            if (!CONTAINS(adj_list[u], v))
                adj_list[u].push_back(v);
        }

        REP(i, n)
        {
            if (dfs_num[i] == -1)
                dfs(i);
        }

        cout << num_scc << '\n';
    }

    return 0;
}