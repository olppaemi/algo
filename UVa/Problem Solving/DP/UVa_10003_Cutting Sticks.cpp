// https://onlinejudge.org/external/100/10003.pdf

#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))
#define INF 1000000000

int length, n;
int c[50];

int memo[1000][1000];

int cut(int left, int right)
{
    if (left + 1 == right)
        return 0;
    int &ans = memo[left][right];
    if (ans != -1)
        return ans;
    ans = INF;
    FOR(i, left + 1, right)
    {
        ans = min(ans, c[right] - c[left] + cut(left, i) + cut(i, right));
    }
    return ans;
}

int main()
{
    c[0] = 0;
    while (scanf("%d", &length), length)
    {
        RESET(memo, -1);
        scanf("%d", &n);
        FOR(i, 1, n + 1)
        {
            scanf("%d", &c[i]);
        }
        c[n + 1] = length;

        printf("The minimum cutting is %d.\n", cut(0, n + 1));
    }
    return 0;
}