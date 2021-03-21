// https://onlinejudge.org/external/104/10424.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define MAX_LEN 30

int love_calculator(int n)
{
    if (n < 10)
        return n;

    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return love_calculator(sum);
}

int love(char *s)
{
    int n = 0;
    REP(i, strlen(s))
    {
        if (isalpha(s[i]))
            n += tolower(s[i]) - 'a' + 1;
    }
    return love_calculator(n);
}

int main()
{
    char s1[MAX_LEN], s2[MAX_LEN];
    while (gets(s1))
    {
        gets(s2);
        int x = love(s1), y = love(s2);
        if (x > y)
            swap(x, y);
        printf("%.2f %%\n", x / (double)y * 100.0);
    }

    return 0;
}