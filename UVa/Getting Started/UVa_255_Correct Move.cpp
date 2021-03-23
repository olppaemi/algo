#include <bits/stdc++.h>
using namespace std;

int main()
{
    int king, queen, queen2;
    while (scanf("%d %d %d", &king, &queen, &queen2) == 3)
    {
        if (king == queen)
        {
            printf("Illegal state\n");
            continue;
        }

        if (((queen2 - queen) % 8 != 0 and queen2 / 8 != queen / 8) or queen == queen2)
        {
            printf("Illegal move\n");
            continue;
        }

        if (((king - queen) % 8 == 0 and (king - queen2) % 8 == 0) or (king / 8 == queen / 8 and king / 8 == queen2 / 8))
        {
            if (king >= min(queen, queen2) and king <= max(queen, queen2))
            {
                printf("Illegal move\n");
                continue;
            }
        }

        int diff = max(king, queen2) - min(king, queen2);
        if (diff == 8 || (diff == 1 and king / 8 == queen2 / 8))
        {
            printf("Move not allowed\n");
            continue;
        }

        if ((king == 0 and queen2 == 9) or (king == 7 and queen2 == 14) or (king == 56 and queen2 == 49) or (king == 63 and queen2 == 54))
            printf("Stop\n");
        else
            printf("Continue\n");
    }

    return 0;
}