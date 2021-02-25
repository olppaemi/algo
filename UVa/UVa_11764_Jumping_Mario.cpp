// https://onlinejudge.org/external/117/11764.pdf

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef tuple<int, int> ii;

ii solution(int n, vi a)
{
    int hi = 0, lo = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] < a[i])
            hi++;
        else if (a[i - 1] > a[i])
            lo++;
    }
    return tie(hi, lo);
}

int main()
{
    int tc;
    scanf("%d", &tc);
    for (int test_case = 1; test_case <= tc; test_case++)
    {
        int n;
        scanf("%d", &n);
        vi a(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        int high_jump, low_jump;
        tie(high_jump, low_jump) = solution(n, a);
        printf("Case %d: %d %d\n", test_case, high_jump, low_jump);
    }
    return 0;
}