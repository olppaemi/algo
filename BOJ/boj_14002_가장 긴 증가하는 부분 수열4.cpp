#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

int n, a[1000];
int p[1000], lis[1000], lis_idx[1000];
int ans[1000], sz = 0;

void LIS(int i)
{
    if (p[i] == -1)
    {
        ans[sz++] = a[i];
        return;
    }
    LIS(p[i]);
    ans[sz++] = a[i];
}

int main()
{
    scanf("%d", &n);
    REP(i, n)
    {
        scanf("%d", &a[i]);
    }

    int len = 0, lis_end = 0;
    memset(p, -1, sizeof(p));
    REP(i, n)
    {
        int pos = lower_bound(lis, lis + len, a[i]) - lis;
        lis[pos] = a[i];
        lis_idx[pos] = i;
        p[i] = pos ? lis_idx[pos - 1] : -1;

        if (pos == len)
        {
            len = pos + 1;
            lis_end = i;
        }
    }

    LIS(lis_end);
    printf("%d\n", sz);
    REP(i, sz)
    {
        printf("%d ", ans[i]);
    }

    return 0;
}