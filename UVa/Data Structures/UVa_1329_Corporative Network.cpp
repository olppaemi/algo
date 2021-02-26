#include <bits/stdc++.h>
using namespace std;
#define REPN(i, n) for (int i = 1; i <= n; i++)

int n;
int parent[20001], dist[20001];

void init()
{
    REPN(i, n)
    {
        parent[i] = i;
        dist[i] = 0;
    }
}

int find(int u)
{
    if (u == parent[u])
        return u;
    int p = find(parent[u]);
    dist[u] += dist[parent[u]];
    return parent[u] = p;
}

void link(int u, int v)
{
    parent[u] = v;
}

int main()
{
    int t, u, v;
    char c;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        init();

        while (scanf(" %c", &c), c != 'O')
        {
            if (c == 'E')
            {
                scanf("%d", &u);
                find(u);
                printf("%d\n", dist[u]);
            }
            else if (c == 'I')
            {
                scanf("%d %d", &u, &v);
                link(u, v);
                dist[u] = abs(u - v) % 1000;
            }
        }
    }

    return 0;
}