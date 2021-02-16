// https://onlinejudge.org/external/123/12356.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

int main()
{
    int s, b, l, r;
    int lefts[100001], rights[100001];
    while (scanf("%d %d", &s, &b), s || b)
    {
        REPN(i, s)
        {
            lefts[i] = i - 1;
            rights[i] = i + 1;
        }
        lefts[1] = rights[s] = -1;
        REP(i, b)
        {
            scanf("%d %d", &l, &r);
            if (lefts[l] == -1)
                printf("* ");
            else
                printf("%d ", lefts[l]);

            if (rights[r] == -1)
                printf("*\n");
            else
                printf("%d\n", rights[r]);

            lefts[rights[r]] = lefts[l];
            rights[lefts[l]] = rights[r];
        }
        printf("-\n");
    }
    return 0;
}