// https://onlinejudge.org/external/4/410.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

int C, S;
int specimens[10];

int main()
{
    int t = 1;
    while (scanf("%d %d", &C, &S) != EOF)
    {
        printf("Set #%d\n", t++);
        RESET(specimens, 0);

        double avg = 0, imbalance = 0;
        REP(i, S)
        {
            scanf("%d", &specimens[i]);
            avg += specimens[i];
        }
        avg /= C;
        sort(specimens, specimens + 2 * C);
        REP(i, C)
        {
            imbalance += abs((specimens[i] + specimens[2 * C - 1 - i]) - avg);
            printf(" %d:", i);
            if (specimens[i])
                printf(" %d", specimens[i]);
            if (specimens[2 * C - 1 - i])
                printf(" %d", specimens[2 * C - 1 - i]);
            puts("");
        }
        printf("IMBALANCE = %.5f\n\n", imbalance);
    }

    return 0;
}