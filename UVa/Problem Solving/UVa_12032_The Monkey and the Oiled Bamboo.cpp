// https://onlinejudge.org/external/120/12032.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

bool can(int k, int n, int ladder[])
{
    int pos = 0;
    REP(i, n)
    {
        if (ladder[i] - pos > k)
            return false;
        else if (ladder[i] - pos == k)
            k--;
        pos = ladder[i];
    }
    return true;
}

int solution(int n, int ladder[])
{

    int lo = 1, hi = ladder[n - 1], mid;
    int ans = 0;

    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (can(mid, n, ladder))
        {
            hi = mid - 1;
            ans = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int t, n;
    int ladder[100000];

    scanf("%d", &t);
    REPN(tc, t)
    {
        scanf("%d", &n);
        REP(i, n)
        {
            scanf("%d", &ladder[i]);
        }
        printf("Case %d: %d\n", tc, solution(n, ladder));
    }

    return 0;
}