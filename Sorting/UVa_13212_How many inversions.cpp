// https://onlinejudge.org/external/132/13212.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INF 1000000000

#define MAX_N 1000010

long long inversion = 0;
int L[MAX_N / 2], R[MAX_N / 2];

void merge(int a[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    REP(i, n1)
    {
        L[i] = a[p + i];
    }

    REP(i, n2)
    {
        R[i] = a[q + i + 1];
    }

    L[n1] = INF;
    R[n2] = INF;

    int i = 0, j = 0;
    FOR(k, p, r + 1)
    {
        if (L[i] <= R[j])
            a[k] = L[i++];
        else
        {
            a[k] = R[j++];
            inversion += n1 - i;
        }
    }
}

void merge_sort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

int main()
{
    int a[MAX_N];
    int n;

    while (scanf("%d", &n), n)
    {
        inversion = 0;
        REP(i, n)
        {
            scanf("%d", &a[i]);
        }

        merge_sort(a, 0, n - 1);
        printf("%lld\n", inversion);
    }

    return 0;
}