// https://onlinejudge.org/external/113/11369.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int t, n;
    int price[20000];

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        REP(i, n)
        {
            scanf("%d", &price[i]);
        }
        sort(price, price + n);
        reverse(price, price + n);
        int ans = 0;
        for (int i = 2; i < n; i += 3)
            ans += price[i];
        printf("%d\n", ans);
    }

    return 0;
}