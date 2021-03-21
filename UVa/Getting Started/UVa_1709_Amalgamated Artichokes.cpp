// https://onlinejudge.org/external/17/1709.pdf

#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; ++i)

int main()
{
    int p, a, b, c, d, n;
    while (scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) == 6)
    {
        double max_decline = 0;
        double mx = p * (sin(a + b) + cos(c + d) + 2.0);
        FOR(k, 2, n + 1)
        {
            double curr = p * (sin(a * k + b) + cos(c * k + d) + 2.0);
            max_decline = max(max_decline, mx - curr);
            mx = max(mx, curr);
        }
        printf("%f\n", max_decline);
    }
    return 0;
}