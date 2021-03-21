// https://onlinejudge.org/external/110/11078.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INF 1000000000

int solution(int n, int a[])
{
    int answer = -INF;
    int mx = a[0];
    FOR(i, 1, n)
    {
        answer = max(answer, mx - a[i]);
        mx = max(mx, a[i]);
    }
    return answer;
}

int main()
{
    int tc;
    int a[100000];
    scanf("%d", &tc);
    while (tc--)
    {
        int n;
        scanf("%d", &n);
        REP(i, n)
        {
            scanf("%d", &a[i]);
        }
        printf("%d\n", solution(n, a));
    }
    return 0;
}