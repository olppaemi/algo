// https://onlinejudge.org/external/4/466.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

char pattern[10][10], target[10][10], tmp[10][10];
int n;

bool same()
{
    REP(i, n)
    {
        REP(j, n)
        {
            if (pattern[i][j] != target[i][j])
                return false;
        }
    }
    return true;
}

void rotate_right()
{
    REP(i, n)
    {
        REP(j, n)
        {
            tmp[j][n - 1 - i] = pattern[i][j];
        }
    }

    REP(i, n)
    {
        REP(j, n)
        {
            pattern[i][j] = tmp[i][j];
        }
    }
}

void reflect()
{
    REP(i, n)
    {
        REP(j, n)
        {
            tmp[n - 1 - i][j] = pattern[i][j];
        }
    }
    REP(i, n)
    {
        REP(j, n)
        {
            pattern[i][j] = tmp[i][j];
        }
    }
}

int main()
{
    int tc = 1;
    while (scanf("%d", &n) == 1)
    {
        REP(i, n)
        {
            REP(j, 2 * n)
            {
                if (j < n)
                    scanf(" %c", &pattern[i][j]);
                else
                    scanf(" %c", &target[i][j - n]);
            }
        }
        int rotation, reflection;
        bool find = false;
        for (reflection = 0; reflection < 2; reflection++)
        {
            for (rotation = 0; rotation < 4; rotation++)
            {
                if (same())
                {
                    find = true;
                    break;
                }
                rotate_right();
            }
            if (find or reflection == 1)
                break;
            reflect();
        }
        printf("Pattern %d was ", tc++);
        if (rotation == 4 and reflection == 1)
        {
            printf("improperly transformed.\n");
        }
        else if (reflection == 0 and rotation == 0)
        {
            printf("preserved.\n");
        }
        else if (reflection == 0)
        {
            printf("rotated %d degrees.\n", 90 * rotation);
        }
        else
        {
            if (rotation)
                printf("reflected vertically and rotated %d degrees.\n", 90 * rotation);
            else
                printf("reflected vertically.\n");
        }
    }

    return 0;
}