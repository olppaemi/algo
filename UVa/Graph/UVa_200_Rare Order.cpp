// https://onlinejudge.org/external/2/200.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

vector<int> adj_list[30], ans;
bitset<30> visited;

void dfs(int u)
{
    visited.set(u);
    for (auto &v : adj_list[u])
    {
        if (!visited[v])
            dfs(v);
    }
    ans.push_back(u);
}

int main()
{
    char s[30] = "", ps[30] = "";
    bitset<30> used;

    while (scanf("%s", s), s[0] != '#')
    {
        for (int i = 0; s[i] and ps[i]; ++i)
        {
            if (ps[i] != s[i])
            {
                int u = ps[i] - 'A', v = s[i] - 'A';
                used.set(u);
                used.set(v);
                adj_list[u].push_back(v);
                break;
            }
        }
        strcpy(ps, s);
    }

    REP(i, 26)
    {
        if (used[i] and !visited[i])
            dfs(i);
    }
    for (int i = ans.size() - 1; i >= 0; --i)
        printf("%c", ans[i] + 'A');
    puts("");

    return 0;
}