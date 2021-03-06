// https://onlinejudge.org/external/4/459.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

vector<set<int>> adj_list;
bool visited[26];

void dfs(int u)
{
    visited[u] = true;
    for (auto &v : adj_list[u])
    {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    int tc;
    string line;
    char c;

    scanf("%d", &tc);
    while (tc--)
    {
        adj_list.clear();
        RESET(visited, 0);
        line = "";

        scanf(" %c", &c);
        getchar();
        int n = c - 'A' + 1;
        adj_list.assign(n, set<int>());
        while (getline(cin, line), line != "")
        {
            int u = line[0] - 'A', v = line[1] - 'A';
            if (u < n and v < n)
            {
                adj_list[u].insert(v);
                adj_list[v].insert(u);
            }
            line = "";
        }

        int num_cc = 0;
        REP(i, n)
        {
            if (!visited[i])
            {
                ++num_cc;
                dfs(i);
            }
        }
        printf("%d\n", num_cc);
        if (tc)
            puts("");
    }

    return 0;
}