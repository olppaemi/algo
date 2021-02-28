// https://onlinejudge.org/external/4/481.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
typedef vector<int> vi;

vi p, A;
vi ans;

void LIS(int i)
{
    if (p[i] == -1)
    {
        ans.push_back(A[i]);
        return;
    }
    LIS(p[i]);
    ans.push_back(A[i]);
}

int main()
{
    int v;
    while (scanf("%d", &v) != EOF)
    {
        A.push_back(v);
    }

    int n = A.size();
    int k = 0, lis_end = 0;
    vi L(n, 0), L_id(n, 0);
    p.assign(n, -1);

    REP(i, n)
    {
        int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();
        L[pos] = A[i];
        L_id[pos] = i;
        p[i] = pos ? L_id[pos - 1] : -1;
        if (pos == k)
        {
            k = pos + 1;
            lis_end = i;
        }
    }

    LIS(lis_end);
    printf("%d\n-\n", ans.size());
    for (auto &x : ans)
        printf("%d\n", x);

    return 0;
}