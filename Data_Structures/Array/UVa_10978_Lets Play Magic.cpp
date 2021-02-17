// https://onlinejudge.org/external/100/10038.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    char card[3], word[21];
    int n;

    while (scanf("%d", &n), n)
    {
        char cards[52][3] = {0};
        int cur = 0, len;
        REP(i, n)
        {
            scanf("%s %s", card, word);
            len = strlen(word);
            while (len)
            {
                if (!strcmp(cards[cur], ""))
                    len--;
                cur++;
                if (cur >= n)
                    cur = 0;
            }
            strcpy(cards[(cur - 1 + n) % n], card);
        }
        REP(i, n)
        {
            if (i != n - 1)
                printf("%s ", cards[i]);
            else
                printf("%s\n", cards[i]);
        }
    }
    return 0;
}