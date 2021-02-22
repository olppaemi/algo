// https://onlinejudge.org/external/118/11849.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
typedef vector<int> vi;

int main()
{
    int n, m, x;

    while (scanf("%d %d", &n, &m), n || m)
    {
        vi a, b, ans;
        REP(i, n)
        {
            scanf("%d", &x);
            a.push_back(x);
        }
        REP(i, m)
        {
            scanf("%d", &x);
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(ans));
        printf("%u\n", ans.size());
    }
    return 0;
}