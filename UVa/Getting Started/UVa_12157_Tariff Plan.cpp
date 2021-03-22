#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n;

    scanf("%d", &tc);
    REPN(t, tc)
    {
        scanf("%d", &n);
        int mile = 0, juice = 0;
        int duration;
        REP(i, n)
        {
            scanf("%d", &duration);
            mile += (duration / 30 + 1) * 10;
            juice += (duration / 60 + 1) * 15;
        }
        printf("Case %d: ", t);
        if (mile < juice)
            printf("Mile %d\n", mile);
        else if (mile > juice)
            printf("Juice %d\n", juice);
        else
            printf("Mile Juice %d\n", juice);
    }

    return 0;
}