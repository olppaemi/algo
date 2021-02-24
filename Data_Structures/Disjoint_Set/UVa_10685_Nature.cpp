// https://onlinejudge.org/external/106/10685.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define RESET(a, b) memset(a, b, sizeof(a))

int parent[5000];
int largest_chain;

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
        largest_chain = max(largest_chain, -tmp);
        if (-parent[u] < parent[v])
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
    int c, r;
    char name[32], name2[32];
    map<string, int> name_to_code;
    int num;

    while (scanf("%d %d", &c, &r), c || r)
    {
        name_to_code.clear();
        largest_chain = 1;
        RESET(parent, -1);
        num = 0;

        REP(i, c)
        {
            scanf("%s", name);
            name_to_code[name] = num++;
        }
        REP(i, r)
        {
            scanf("%s %s", name, name2);
            merge(name_to_code[name], name_to_code[name2]);
        }
        printf("%d\n", largest_chain);
    }

    return 0;
}