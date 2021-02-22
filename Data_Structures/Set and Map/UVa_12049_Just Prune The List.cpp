// https://onlinejudge.org/external/120/12049.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

int main()
{
    int tc, n, m, val;
    scanf("%d", &tc);
    while (tc--)
    {
        map<int, int> a, b;
        set<int> nums;
        scanf("%d %d", &n, &m);

        REP(i, n)
        {
            scanf("%d", &val);
            a[val]++;
            nums.insert(val);
        }
        REP(i, m)
        {
            scanf("%d", &val);
            b[val]++;
            nums.insert(val);
        }
        int ans = 0;
        for (auto &x : nums)
        {
            ans += abs(a[x] - b[x]);
        }
        printf("%d\n", ans);
    }
    return 0;
}