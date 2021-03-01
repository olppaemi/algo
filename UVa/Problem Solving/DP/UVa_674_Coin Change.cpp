// https://onlinejudge.org/external/6/674.pdf

#include <bits/stdc++.h>
using namespace std;
#define RESET(a, b) memset(a, b, sizeof(a))

int memo[5][7500];
int n = 5, coins[] = {1, 5, 10, 25, 50};
int ways(int type, int value)
{
    if (value == 0)
        return 1;
    if ((value < 0) or type == n)
        return 0;
    int &ans = memo[type][value];
    if (ans != -1)
        return ans;
    return ans = ways(type + 1, value) + ways(type, value - coins[type]);
}

int w[7500];
void ways2()
{
    w[0] = 1;
    for (auto &value : coins)
    {
        for (int i = value; i <= 7500; ++i)
        {
            w[i] += w[i - value];
        }
    }
}

int main()
{
    ways2();
    int v;
    // RESET(memo, -1);
    while (scanf("%d", &v) != EOF)
    {
        printf("%d\n", w[v]);
        // printf("%d\n", ways(0, v));
    }
    return 0;
}