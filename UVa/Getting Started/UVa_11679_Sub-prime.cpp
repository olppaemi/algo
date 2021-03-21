#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)

int main()
{
    int b, n;
    int debtor, creditor, debenture_value;

    int bank[21];
    while (scanf("%d %d", &b, &n), b | n)
    {
        REPN(i, b)
        {
            scanf("%d", &bank[i]);
        }

        REP(i, n)
        {
            scanf("%d %d %d", &debtor, &creditor, &debenture_value);
            bank[debtor] -= debenture_value;
            bank[creditor] += debenture_value;
        }

        bool possible = true;
        REPN(i, b)
        {
            if (bank[i] < 0)
            {
                possible = false;
                break;
            }
        }
        printf("%c\n", possible ? 'S' : 'N');
    }

    return 0;
}