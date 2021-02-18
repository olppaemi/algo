// https://onlinejudge.org/external/127/12709.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    int t;
    int l, w, h;
    vii a;

    while (scanf("%d", &t), t)
    {
        a.clear();
        REP(i, t)
        {
            scanf("%d %d %d", &l, &w, &h);
            a.push_back({h, l * w * h});
        }
        sort(a.rbegin(), a.rend());
        printf("%d\n", a[0].second);
    }

    return 0;
}