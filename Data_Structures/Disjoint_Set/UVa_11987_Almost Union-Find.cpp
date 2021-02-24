// https://onlinejudge.org/external/119/11987.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

const int MAXN = 200010;
int parent[MAXN], sum[MAXN];
void make_set(int n)
{
    REPN(i, n)
    {
        parent[i] = i + n;
        parent[i + n] = -1;
        sum[i + n] = i;
    }
}

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
            sum[v] += sum[u];
        }
        else
        {
            parent[v] = u;
            parent[u] = tmp;
            sum[u] += sum[v];
        }
    }
}

void move(int u, int v)
{
    int uroot = find(u);
    int vroot = find(v);
    if (uroot != vroot)
    {
        parent[u] = vroot;
        sum[vroot] += u;
        sum[uroot] -= u;
        parent[vroot]--;
        parent[uroot]++;
    }
}

int main()
{
    int n, m;
    int cmd, p, q;

    while (scanf("%d %d", &n, &m) != EOF)
    {
        make_set(n);
        REP(i, m)
        {
            scanf("%d", &cmd);
            if (cmd == 1)
            {
                scanf("%d %d", &p, &q);
                merge(p, q);
            }
            else if (cmd == 2)
            {
                scanf("%d %d", &p, &q);
                move(p, q);
            }
            else if (cmd == 3)
            {
                scanf("%d", &p);
                printf("%d %d\n", -parent[find(p)], sum[find(p)]);
            }
        }
    }

    return 0;
}