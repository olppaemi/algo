// https://onlinejudge.org/external/120/12015.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

int main()
{
    int tc;
    char url[10][101];
    int relevance[10];

    scanf("%d", &tc);
    REPN(test_case, tc)
    {
        int mx = 0;
        REP(i, 10)
        {
            scanf("%s %d", url[i], &relevance[i]);
            mx = max(mx, relevance[i]);
        }

        printf("Case #%d:\n", test_case);
        REP(i, 10)
        {
            if (relevance[i] == mx)
                printf("%s\n", url[i]);
        }
    }

    return 0;
}