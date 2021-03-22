#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)

int main()
{
    int a, b, x;
    int ans1, ans2;

    while (scanf("%d %d", &a, &b), a | b)
    {
        int Alice[100001] = {}, Betty[100001] = {};
        ans1 = ans2 = 0;
        REP(i, a)
        {
            scanf("%d", &x);
            ++Alice[x];
        }
        REP(i, b)
        {
            scanf("%d", &x);
            ++Betty[x];
        }

        REPN(i, 100000)
        {
            if (Alice[i] and !Betty[i])
                ++ans1;
            if (Betty[i] and !Alice[i])
                ++ans2;
        }
        printf("%d\n", min(ans1, ans2));
    }

    return 0;
}