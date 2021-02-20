// https://onlinejudge.org/external/113/11321.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
typedef vector<int> vi;

int n, m;

bool cmp(int a, int b)
{
    if (a % m != b % m)
        return a % m < b % m;
    if (a & 1)
    {
        if (b & 1) // odd, odd
            return a > b;
        // odd, even
        return true;
    }
    // even, odd
    if (b & 1)
        return false;

    // even, even
    return a < b;
}

int main()
{
    int x;
    vi a(10005);

    while (scanf("%d %d", &n, &m), printf("%d %d\n", n, m), n)
    {
        REP(i, n)
        {
            scanf("%d", &a[i]);
        }
        sort(a.begin(), a.begin() + n, cmp);
        REP(i, n)
        {
            printf("%d\n", a[i]);
        }
    }

    return 0;
}