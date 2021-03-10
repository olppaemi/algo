// https://onlinejudge.org/external/117/11747.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

int V, E;
int parent[1000];

int find(int u)
{
    return parent[u] < 0 ? u : parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u != v)
    {
        int tmp = parent[u] + parent[v];
        if (-parent[u] < -parent[v])
        {
            parent[u] = v;
            parent[v] = tmp;
        }
        else
        {
            parent[v] = u;
            parent[u] = tmp;
        }
    }
}

void kruskal()
{
    vector<tuple<int, int, int>> AL;
    RESET(parent, -1);

    int u, v, w;
    REP(i, E)
    {
        scanf("%d %d %d", &u, &v, &w);
        AL.push_back({w, u, v});
    }
    sort(AL.begin(), AL.end());
    vector<int> ans;

    for (auto &[w, u, v] : AL)
    {
        if (find(u) != find(v))
            merge(u, v);
        else
            ans.push_back(w);
    }
    if (!ans.empty())
    {
        REP(i, ans.size())
        {
            printf("%d%c", ans[i], (i == ans.size() - 1) ? '\n' : ' ');
        }
    }
    else
        printf("forest\n");
}

int main()
{
    while (scanf("%d %d", &V, &E), V | E)
    {
        kruskal();
    }

    return 0;
}