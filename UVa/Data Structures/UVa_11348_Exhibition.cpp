// https://onlinejudge.org/external/113/11348.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define RESET(a) memset(a, 0, sizeof(a))

int main()
{
    int tc, n, m, x;
    int count[51];

    scanf("%d", &tc);
    REPN(test_case, tc)
    {
        RESET(count);
        printf("Case %d: ", test_case);

        set<int> stamp_owner[10001];
        scanf("%d", &n);
        REP(i, n)
        {
            scanf("%d", &m);
            REP(j, m)
            {
                scanf("%d", &x);
                stamp_owner[x].insert(i);
            }
        }

        int total = 0;
        REP(i, 10001)
        {
            if (stamp_owner[i].size() == 1)
            {
                count[*stamp_owner[i].begin()]++;
                total++;
            }
        }
        if (total)
        {
            REP(i, n)
            {
                printf(i != n - 1 ? "%.6f%% " : "%.6f%%\n", (double)count[i] / total * 100);
            }
        }
        else
            puts("");
    }

    return 0;
}