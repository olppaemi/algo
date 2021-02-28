// https://onlinejudge.org/external/106/10684.pdf

#include <iostream>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    int a[10000];
    while (scanf("%d", &n), n)
    {
        REP(i, n)
        {
            scanf("%d", &a[i]);
        }
        int sum = 0, ans = 0;
        REP(i, n)
        {
            sum += a[i];
            ans = max(ans, sum);
            if (sum < 0)
                sum = 0;
        }
        if (ans > 0)
            printf("The maximum winning streak is %d.\n", ans);
        else
            printf("Losing streak.\n");
    }
    return 0;
}