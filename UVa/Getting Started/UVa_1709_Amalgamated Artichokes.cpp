// https://onlinejudge.org/external/17/1709.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

double price(int p, int a, int b, int c, int d, int k)
{
    return p * (sin(a * k + b) + cos(c * k + d) + 2.0);
}

int main()
{
    vector<double> arr(1000000), change(1000000);
    int p, a, b, c, d, n;
    while (scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) == 6)
    {
        REP(k, n)
        {
            arr[k] = price(p, a, b, c, d, k + 1);
        }

        REP(i, n - 1)
        {
            change[i] = arr[i] - arr[i + 1];
        }

        double sum = 0, ans = 0;
        REP(i, n - 1)
        {
            sum += change[i];
            ans = max(ans, sum);
            if (sum < 0)
                sum = 0;
        }
        printf("%f\n", abs(ans));
    }
    return 0;
}