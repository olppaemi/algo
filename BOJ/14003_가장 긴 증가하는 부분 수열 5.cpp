#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

#define MAX_N 1000001

int n, A[MAX_N];
int L[MAX_N], L_id[MAX_N], p[MAX_N];

void print_lis(int i)
{
    if (p[i] == -1)
    {
        printf("%d ", A[i]);
        return;
    }
    print_lis(p[i]);
    printf("%d ", A[i]);
}

int main()
{    
    scanf("%d", &n);
    REP(i, n) scanf("%d", &A[i]);

    int k = 0, lis_end;

    RESET(p, -1);
    REP(i, n)
    {
        int pos = lower_bound(L, L + k, A[i]) - L;
        L[pos] = A[i];
        L_id[pos] = i;
        p[i] = pos ? L_id[pos - 1] : -1;
        if (k == pos)
        {
            k = pos + 1;
            lis_end = i;
        }
    }
    printf("%d\n", k);
    print_lis(lis_end);
    
    return 0;
}