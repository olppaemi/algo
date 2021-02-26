// https://onlinejudge.org/external/116/11621.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))

int main()
{
    long long n;
    vector<long long> vll;

    REP(i, 32)
    {
        REP(j, 32)
        {
            double p = pow(2, i) * pow(3, j);
            if (p <= 1LL << 50)
                vll.push_back(p);
        }
    }

    SORT(vll);
    while (scanf("%lld", &n), n)
    {
        printf("%lld\n", *lower_bound(ALL(vll), n));
    }

    return 0;
}