// https://onlinejudge.org/external/130/13048.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

int main()
{
    int tc;
    char road[51];
    unsigned long long spot; // bitmask
    scanf("%d", &tc);
    REPN(test_case, tc)
    {

        printf("Case %d: ", test_case);
        scanf("%s", road);
        spot = (1ull << strlen(road)) - 1;
        REP(i, strlen(road))
        {
            if (road[i] == 'D')
                spot &= ~(1ull << i);
            else if (road[i] == 'B')
            {
                spot &= ~((1ull << i) | (1ull << i - 1) | (1ull << i - 2));
            }
            else if (road[i] == 'S')
            {
                spot &= ~((1ull << i) | (1ull << i - 1) | (1ull << i + 1));
            }
        }
        printf("%d\n", __builtin_popcountll(spot));
    } 
    return 0;
}