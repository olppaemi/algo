// https://onlinejudge.org/external/2/247.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

typedef vector<int> vi;
typedef pair<int, int> ii;

int n, m;
map<string, int> id;
map<int, string> id_to_name;
int id_counter;

vector<vector<int>> adj_list;
vector<int> dfs_num, dfs_low, visited;
stack<int> st;
int dfs_counter, num_scc;
vector<vector<int>> ans;

void dfs_visit(int u)
{
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    st.push(u);
    visited[u] = 1;

    for (auto &v : adj_list[u])
    {
        if (dfs_num[v] == -1)
            dfs_visit(v);
        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_low[u] == dfs_num[u])
    {
        ++num_scc;
        vector<int> scc;
        while (1)
        {
            int v = st.top();
            scc.push_back(v);
            st.pop();
            visited[v] = 0;
            if (u == v)
                break;
        }
        ans.push_back(scc);
    }
}

void dfs()
{
    dfs_counter = num_scc = 0;
    dfs_num.assign(n, -1);
    dfs_low.assign(n, 0);
    visited.assign(n, 0);
    while (!st.empty())
        st.pop();
    REP(i, n)
    {
        if (dfs_num[i] == -1)
            dfs_visit(i);
    }
}

int main()
{
    int tc = 0;
    string s1, s2;
    while (cin >> n >> m, n || m)
    {
        if (tc)
            cout << '\n';
        ans.clear();
        adj_list.assign(n, vector<int>());
        id_counter = 0;
        id.clear();
        id_to_name.clear();

        REP(i, m)
        {
            cin >> s1 >> s2;
            if (id.find(s1) == id.end())
            {
                id_to_name[id_counter] = s1;
                id[s1] = id_counter++;
            }
            if (id.find(s2) == id.end())
            {
                id_to_name[id_counter] = s2;
                id[s2] = id_counter++;
            }
            if (find(adj_list[id[s1]].begin(), adj_list[id[s1]].end(), id[s2]) == adj_list[id[s1]].end())
                adj_list[id[s1]].push_back(id[s2]);
        }

        dfs();

        cout << "Calling circles for data set " << ++tc << ":\n";
        for (auto &ls : ans)
        {
            cout << id_to_name[ls[0]];
            for (int j = 1; j < ls.size(); ++j)
            {
                cout << ", " << id_to_name[ls[j]];
            }
            cout << '\n';
        }
    }
    return 0;
}