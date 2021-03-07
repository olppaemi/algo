// https://www.acmicpc.net/problem/2252

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)

typedef vector<int> vi;

int n, m;
vi adj_list[32001];
bool visited[32001];
vi ans;

void toposort(int u)
{
    visited[u] = true;
    for (auto &v : adj_list[u])
    {
        if (!visited[v])
            toposort(v);
    }
    ans.push_back(u);
}

int main()
{
    scanf("%d %d", &n, &m);

    int u, v;
    REP(i, m)
    {
        scanf("%d %d", &u, &v);
        adj_list[u].push_back(v);
    }
    FOR(i, 1, n + 1)
    {
        if (!visited[i])
            toposort(i);
    }
    reverse(ans.begin(), ans.end());
    for (auto &x : ans)
        printf("%d ", x);

    return 0;
}