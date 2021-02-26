#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define RESET(a, b) memset(a, b, sizeof(a))

int n;
int parent[30001];
int largest_group;

int find(int u)
{
    if (parent[u] >= 0)
        return parent[u] = find(parent[u]);

    return u;
}

void merge(int u, int v)
{
    u = find(u), v = find(v);
    if (u != v)
    {
        int tmp = parent[u] + parent[v];
        largest_group = max(largest_group, -tmp);
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

int main()
{
    int t;
    int m, u, v;

    scanf("%d", &t);
    while (t--)
    {
        RESET(parent, -1);
        largest_group = 1;

        scanf("%d %d", &n, &m);
        REP(i, m)
        {
            scanf("%d %d", &u, &v);
            merge(u, v);
        }
        printf("%d\n", largest_group);
    }

    return 0;
}