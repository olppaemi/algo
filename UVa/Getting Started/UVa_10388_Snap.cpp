#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)

char up[2][100], down[2][100];
int pu[2], pd[2], len[2];

int simulate()
{
    REP(i, 1000)
    {
        if (pu[0] + len[0] == 0)
            return 1;
        if (pu[1] + len[1] == 0)
            return -1;

        up[0][pu[0]++] = down[0][pd[0]++];
        up[1][pu[1]++] = down[1][pd[1]++];
        if (up[0][pu[0] - 1] == up[1][pu[1] - 1])
        {
            int p = random() / 141 % 2;
            REP(j, pu[1 - p])
            {
                up[p][pu[p]++] = up[1 - p][j];
            }
            pu[1 - p] = 0;
            if (p == 0)
                printf("Snap! for Jane: ");
            else
                printf("Snap! for John: ");

            for (int j = pu[p] - 1; j >= 0; j--)
                printf("%c", up[p][j]);
            puts("");
        }

        // when the face-down pile is exhausted,
        if (pd[0] == len[0])
        {
            len[0] = pu[0];
            pd[0] = pu[0] = 0;
            REP(j, len[0])
            {
                down[0][j] = up[0][j];
            }
        }
        if (pd[1] == len[1])
        {
            len[1] = pu[1];
            pd[1] = pu[1] = 0;
            REP(j, len[1])
            {
                down[1][j] = up[1][j];
            }
        }
    }
    return 0;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while (tc--)
    {
        scanf("%s %s", down[0], down[1]);
        len[0] = len[1] = strlen(down[0]);
        pu[0] = pu[1] = pd[0] = pd[1] = 0;

        int ans = simulate();
        if (ans == 0)
            puts("Keeps going and going ...");
        else if (ans == 1)
            puts("John wins.");
        else
            puts("Jane wins.");

        if (tc)
            puts("");
    }

    return 0;
}