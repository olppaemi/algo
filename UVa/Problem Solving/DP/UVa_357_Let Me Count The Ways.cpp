// https://onlinejudge.org/external/3/357.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)

int coins[] = {1, 5, 10, 25, 50};
long long ways[30001] = {1};

int main()
{
    REP(i, 5)
    {
        FOR(j, coins[i], 30001)
        {
            ways[j] += ways[j - coins[i]];
        }
    }
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (ways[n] == 1)
            printf("There is only 1 way to produce %d cents change.\n", n);
        else
            printf("There are %lld ways to produce %d cents change.\n", ways[n], n);
    }

    return 0;
}