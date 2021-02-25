// https://onlinejudge.org/external/113/11340.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    int tc, k, m;
    char str[10010];
    long long v, ans;

    scanf("%d", &tc);
    while (tc--)
    {
        long long $[256] = {};
        ans = 0;

        scanf("%d ", &k);
        REP(i, k)
        {
            gets(str);
            sscanf(str + 2, "%lld", &v);
            $[str[0] + 128] = v;
        }
        scanf("%d ", &m);
        REP(i, m)
        {
            gets(str);
            REP(j, strlen(str))
            {
                ans += $[str[j] + 128];
            }
        }
        printf("%lld.%02lld$\n", ans / 100, ans % 100);
    }
    return 0;
}