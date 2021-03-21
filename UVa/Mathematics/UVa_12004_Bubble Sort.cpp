#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)

int main()
{
    int tc, n;

    scanf("%d", &tc);
    REPN(t, tc)
    {
        scanf("%d", &n);

        printf("Case %d: ", t);
        long long ans = (long long)n * (n - 1);
        if (ans % 4 == 0)
            printf("%lld\n", ans / 4);
        else
            printf("%lld/2\n", ans / 2);
    }

    return 0;
}