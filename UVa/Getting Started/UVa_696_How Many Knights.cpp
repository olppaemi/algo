#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    while (scanf("%d %d", &m, &n), m | n)
    {
        int a = min(m, n), b = max(m, n), ans;

        if (a == 1)
            ans = b;
        else if (a == 2)
        {
            int c = b % 4;
            if (c)
                ans = (b / 4) * 4 + (c > 1 ? 4 : 2);
            else
                ans = (b / 4) * 4;
        }
        else
            ans = (a * b + 1) / 2;
        printf("%d knights may be placed on a %d row %d column board.\n", ans, m, n);
    }

    return 0;
}