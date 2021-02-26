// https://onlinejudge.org/external/124/12455.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define LSOne(x) ((x) & -(x))

const char *solution(int x, int n, int a[])
{
    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        int mask = i;
        while (mask)
        {
            int two_pow_j = LSOne(mask);
            int j = __builtin_ctz(two_pow_j);
            sum += a[j];
            mask -= two_pow_j;
        }
        if (sum == x)
            return "YES";
    }
    return "NO";
}

int main()
{
    int t, n, p;
    int a[1000];

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &p);
        REP(i, p)
        {
            scanf("%d", &a[i]);
        }
        printf("%s\n", solution(n, p, a));
    }

    return 0;
}