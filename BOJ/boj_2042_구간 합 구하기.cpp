// # https://www.acmicpc.net/problem/2042

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

typedef long long ll;
typedef vector<ll> vll;

#define LSOne(x) ((x) & -(x))
vll ft;

void build(int m, vll &a)
{
    ft.assign(m + 1, 0);
    REPN(i, m)
    {
        ft[i] += a[i];
        if (i + LSOne(i) <= m)
            ft[i + LSOne(i)] += ft[i];
    }
}

ll rsq(int i)
{
    ll sum = 0;
    for (; i; i -= LSOne(i))
        sum += ft[i];
    return sum;
}

ll rsq(int i, int j)
{
    return rsq(j) - rsq(i - 1);
}

void update(int i, ll v)
{
    for (; i < (int)ft.size(); i += LSOne(i))
        ft[i] += v;
}

int main()
{
    int n, m, k, x;
    int a, b;
    ll c;
    vll arr;

    scanf("%d %d %d", &n, &m, &k);
    arr.resize(n + 1);

    REPN(i, n)
    {
        scanf("%d", &arr[i]);
    }
    build(n, arr);

    REP(i, m + k)
    {
        scanf("%d %d %lld", &a, &b, &c);
        if (a == 1)
        {
            update(b, c - arr[b]);
            arr[b] = c;
        }
        else
        {
            printf("%lld\n", rsq(b, c));
        }
    }

    return 0;
}