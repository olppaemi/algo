// https://onlinejudge.org/external/107/10751.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n;

    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d", &n);
        if (n == 1)
            printf("0.000\n");
        else if (n == 2)
            printf("4.000\n");
        else
            printf("%.3f\n", 4 * (n - 1) + sqrt(2) * (n - 2) * (n - 2));
        if (tc)
            puts("");
    }

    return 0;
}