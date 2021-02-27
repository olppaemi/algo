// https://onlinejudge.org/external/123/12321.pdf

#include <iostream>
#include <algorithm>

using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

int L, G;
pair<int, int> interval[10000];

int solve()
{
    int n = G;
    int i, covered, next_covered;
    int ans = 0;

    sort(interval, interval + n);
    i = covered = next_covered = 0;
    while (i < n)
    {
        int pos = -1;
        while (i < n and interval[i].first <= covered)
        {
            if (interval[i].second > next_covered)
            {
                next_covered = interval[i].second;
                pos = i;
            }
            ++i;
        }
        if (pos < 0)
            break;
        ++ans;
        covered = next_covered;

        if (covered >= L)
            break;
        i = pos + 1;
    }
    if (covered < L)
        return -1;
    else
        return G - ans;
}

int main()
{
    int x, r;
    while (scanf("%d %d", &L, &G), L || G)
    {
        REP(i, G)
        {
            scanf("%d %d", &x, &r);
            interval[i] = {max(x - r, 0), min(x + r, L)};
        }
        printf("%d\n", solve());
    }

    return 0;
}