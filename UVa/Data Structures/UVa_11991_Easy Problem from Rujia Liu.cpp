// https://onlinejudge.org/external/119/11991.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

int main()
{
    int n, m, x, k, v;

    while (scanf("%d %d", &n, &m) != EOF)
    {
        unordered_map<int, vector<int>> a;
        REPN(i, n)
        {
            scanf("%d", &x);
            a[x].push_back(i);
        }

        REP(i, m)
        {
            scanf("%d %d", &k, &v);
            if (a[v].size() >= k)
            {
                printf("%d\n", a[v][k - 1]);
            }
            else
                printf("0\n");
        }
    }

    return 0;
}