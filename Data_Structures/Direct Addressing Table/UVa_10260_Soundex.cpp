// https://onlinejudge.org/external/102/10260.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    char s[30], c, prev;
    while (gets(s))
    {
        prev = -1;
        REP(i, strlen(s))
        {
            c = s[i];
            if (c == 'B' or c == 'F' or c == 'P' or c == 'V')
            {
                if (prev != 1)
                    printf("1");
                prev = 1;
            }
            else if (c == 'C' or c == 'G' or c == 'J' or c == 'K' or c == 'Q' or c == 'S' or c == 'X' or c == 'Z')
            {
                if (prev != 2)
                    printf("2");
                prev = 2;
            }
            else if (c == 'D' or c == 'T')
            {
                if (prev != 3)
                    printf("3");
                prev = 3;
            }
            else if (c == 'L')
            {
                if (prev != 4)
                    printf("4");
                prev = 4;
            }
            else if (c == 'M' or c == 'N')
            {
                if (prev != 5)
                    printf("5");
                prev = 5;
            }
            else if (c == 'R')
            {
                if (prev != 6)
                    printf("6");
                prev = 6;
            }
            else
                prev = -1;
        }
        puts("");
    }

    return 0;
}