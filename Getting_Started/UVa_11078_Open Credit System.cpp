// https://onlinejudge.org/external/110/11078.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INF 1000000000
typedef vector<int> vi;
typedef tuple<int, int> ii;

int solution(int n, int a[])
{
    int answer = -INF;
    int max = a[0];
    FOR(i, 1, n)
    {
        if (max - a[i] > answer)
            answer = max - a[i];
        if (a[i] > max)
            max = a[i];
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