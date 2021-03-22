#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)

int solve(char *s1, char *s2)
{
    int n = strlen(s1);
    int overall_diff = 0, diff = 0, one2zero = 0, zero2one = 0;

    REP(i, n)
    {
        if (s1[i] != s2[i])
        {
            ++overall_diff;
            if (s1[i] == '?' and s2[i] == '1')
                ++diff;
            else if (s1[i] == '0' and s2[i] == '1')
            {
                ++zero2one;
                ++diff;
            }
            else if (s1[i] == '1' and s2[i] == '0')
            {
                ++one2zero;
                --diff;
            }
        }
    }
    if (diff < 0)
        return -1;

    return overall_diff - min(one2zero, zero2one);
}

int main()
{
    int tc;
    char s1[101], s2[101];

    scanf("%d", &tc);
    REPN(t, tc)
    {
        scanf("%s %s", s1, s2);
        printf("Case %d: %d\n", t, solve(s1, s2));
    }

    return 0;
}