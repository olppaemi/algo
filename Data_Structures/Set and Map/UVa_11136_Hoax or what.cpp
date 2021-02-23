// https://onlinejudge.org/external/111/11136.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    int days, k, tmp;
    while (scanf("%d", &days), days)
    {
        multiset<int> bills;
        long long answer = 0;
        REP(i, days)
        {
            scanf("%d", &k);
            REP(j, k)
            {
                scanf("%d", &tmp);
                bills.insert(tmp);
            }
            auto highest = --bills.end(), lowest = bills.begin();
            answer += *highest - *lowest;
            bills.erase(highest);
            bills.erase(lowest);
        }
        printf("%lld\n", answer);
    }

    return 0;
}