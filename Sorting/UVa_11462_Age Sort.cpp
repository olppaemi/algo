// https://onlinejudge.org/external/114/11462.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

int main()
{
    int age[100];
    int n, x;

    while (scanf("%d", &n), n)
    {
        memset(age, 0, sizeof(age));
        REP(i, n)
        {
            scanf("%d", &x);
            age[x]++;
        }
        bool start = true;
        REPN(i, 99)
        {
            REP(j, age[i])
            {
                if (start)
                {
                    printf("%d", i);
                    start = false;
                }
                else
                    printf(" %d", i);
            }
        }
        puts("");
    }

    return 0;
}