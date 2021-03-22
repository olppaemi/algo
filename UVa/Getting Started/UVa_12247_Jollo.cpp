#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, x, y;

    while (scanf("%d %d %d %d %d", &a, &b, &c, &x, &y), a | b | c | x | y)
    {
        int taken[53] = {};
        taken[a] = taken[b] = taken[c] = taken[x] = taken[y] = 1;

        int her[3] = {a, b, c};
        int his[2] = {x, y};
        sort(her, her + 3);
        sort(his, his + 2);

        int card = 53;

        if (his[0] > her[2])
        {
            for (int i = 1; i <= 52 and i < card; ++i)
                if (!taken[i])
                    card = i;
        }

        if (his[1] > her[2])
        {
            for (int i = her[2] + 1; i <= 52 and i < card; ++i)
                if (!taken[i])
                    card = i;
        }

        if (his[0] > her[1])
        {
            for (int i = her[1] + 1; i <= 52 and i < card; ++i)
                if (!taken[i])
                    card = i;
        }

        if (card == 53)
            card = -1;

        printf("%d\n", card);
    }

    return 0;
}