// https://onlinejudge.org/external/112/11203.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

const char *solution(int n, char s[])
{
    int x = 0, y = 0, z = 0;
    int m_idx = -1, e_idx = -1;
    int cnt_m = 0, cnt_e = 0;
    int state = 0;
    REP(i, n)
    {
        if (s[i] != 'M' and s[i] != 'E' and s[i] != '?')
            return "no-theorem";
        if (s[i] == 'M')
        {
            m_idx = i;
            cnt_m++;
            state = 1;
        }
        else if (s[i] == 'E')
        {
            e_idx = i;
            cnt_e++;
            state = 2;
        }
        else if (state == 0)
            x++;
        else if (state == 1)
            y++;
        else if (state == 2)
            z++;
    }
    if (cnt_m == 1 and cnt_e == 1 and m_idx < e_idx)
    {
        if (x >= 1 and y >= 1 and x + y == z)
            return "theorem";
    }
    return "no-theorem";
}

int main()
{
    int n;
    char s[64];

    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", s);
        printf("%s\n", solution(strlen(s), s));
    }
    return 0;
}