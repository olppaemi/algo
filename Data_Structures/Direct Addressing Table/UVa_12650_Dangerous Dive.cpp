// https://onlinejudge.org/external/126/12650.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define RESET(a) memset(a, 0, sizeof(a))

int main()
{
    int n, r, x;
    bool returned[10001];
    while (scanf("%d %d", &n, &r) == 2)
    {
        RESET(returned);
        REP(i, r)
        {
            scanf("%d", &x);
            returned[x] = true;
        }
        if (n == r)
        {
            printf("*\n");
            continue;
        }

        REPN(i, n)
        {
            if (!returned[i])
                printf("%d ", i);
        }
        puts("");
    }

    return 0;
}