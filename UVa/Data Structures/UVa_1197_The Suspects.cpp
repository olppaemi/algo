#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define RESET(a, b) memset(a, b, sizeof(a))

int n;
int parent[30000];

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
    int m, k, x;

    while (scanf("%d %d", &n, &m), n || m)
    {
        RESET(parent, -1);
        while (m--)
        {
            scanf("%d", &k);
            int a[k];
            REP(i, k)
            {
                scanf("%d", &a[i]);
            }

            REP(i, k - 1)
            {
                merge(a[i], a[i + 1]);
            }
        }
        printf("%d\n", -parent[find(0)]);
    }

    return 0;
}