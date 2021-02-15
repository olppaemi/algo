// https://onlinejudge.org/external/117/11799.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
typedef vector<int> vi;
typedef tuple<int, int> ii;

int main()
{
    int tc;
    scanf("%d", &tc);

    REPN(test_case, tc)
    {
        int mx = 0;
        int n, x;
        scanf("%d", &n);
        REP(i, n)
        {
            scanf("%d", &x);
            if (x > mx)
                mx = x;
        }

        printf("Case %d: %d\n", test_case, mx);
    }

    return 0;
}