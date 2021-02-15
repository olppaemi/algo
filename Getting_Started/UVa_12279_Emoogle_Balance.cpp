// https://onlinejudge.org/external/122/12279.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
typedef vector<int> vi;
typedef tuple<int, int> ii;

int main()
{
    int tc = 1;
    int x;
    while (1)
    {
        int n, answer = 0;
        scanf("%d", &n);
        if (!n)
            break;
        REP(i, n)
        {
            scanf("%d", &x);
            if (x > 0)
                answer++;
            else if (x == 0)
                answer--;
        }

        printf("Case %d: %d\n", tc++, answer);
    }

    return 0;
}