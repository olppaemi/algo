// https://onlinejudge.org/external/117/11729.pdf

#include <iostream>
#include <algorithm>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)

int main()
{
    int n, tc = 0;
    pair<int, int> soldier[10000];
    while (scanf("%d", &n), n)
    {
        REP(i, n)
        {
            scanf("%d %d", &soldier[i].second, &soldier[i].first);
        }
        sort(soldier, soldier + n);
        reverse(soldier, soldier + n);
        int complete = soldier[0].first + soldier[0].second;
        int time = soldier[0].second;
        FOR(i, 1, n)
        {
            time += soldier[i].second;
            if (time + soldier[i].first > complete)
            {
                complete = time + soldier[i].first;
            }
        }
        printf("Case %d: %d\n", ++tc, complete);
    }

    return 0;
}