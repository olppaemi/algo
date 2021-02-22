// https://onlinejudge.org/external/126/12626.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

const char *pizza = "MARGARITA";
int required[26] = {};

bool can_make(int ingredients[])
{
    REP(i, 26)
    {
        if (ingredients[i] < required[i])
            return false;
    }
    return true;
}

void make(int ingredients[])
{
    REP(i, 26)
    {
        if (required[i])
            ingredients[i] -= required[i];
    }
}

int main()
{
    REP(i, strlen(pizza))
    {
        required[pizza[i] - 'A']++;
    }

    int tc;
    char str[610];
    scanf("%d ", &tc);
    while (tc--)
    {
        int ingredients[26] = {}, ans = 0;
        gets(str);
        REP(i, strlen(str))
        {
            ingredients[str[i] - 'A']++;
        }
        while (can_make(ingredients))
        {
            make(ingredients);
            ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}