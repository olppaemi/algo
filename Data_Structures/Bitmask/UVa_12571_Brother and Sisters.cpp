// https://onlinejudge.org/external/125/12571.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        unsigned int n, q, x, a, mx;
        unsigned int query[256] = {0};

        scanf("%u %u", &n, &q);
        REP(i, n)
        {
            scanf("%u", &x);
            query[x & 0xff] = 1;
        }

        REP(i, q)
        {
            scanf("%u", &a);
            mx = 0;
            REP(j, 256)
            {
                if (query[j] and (a & j) > mx)
                    mx = a & j;
            }
            printf("%u\n", mx);
        }
    }
    return 0;
}