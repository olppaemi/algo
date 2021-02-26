// https://onlinejudge.org/external/115/11577.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    int tc;
    char str[200];

    scanf("%d ", &tc);
    while (tc--)
    {
        int alpha[26] = {}, mx = 0;
        gets(str);
        REP(i, strlen(str))
        {
            if (isalpha(str[i]))
            {
                int idx = tolower(str[i]) - 'a';
                alpha[idx]++;
                if (alpha[idx] > mx)
                    mx = alpha[idx];
            }
        }
        REP(i, 26)
        {
            if (alpha[i] == mx)
                printf("%c", i + 'a');
        }
        puts("");
    }
    return 0;
}