#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))
#define INF 1000000000
using namespace std;

int dp[1000005], p[1000005];

int main(void)
{    
    int n;
    scanf("%d", &n);
    fill(dp, dp + n + 1, INF);
    dp[1] = 0;
    for (int i = 1; i < n; i++)
    {
        if (dp[i + 1] > dp[i] + 1)
        {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
            p[i + 1] = i;
        }
        if (i * 2 <= n && dp[i * 2] > dp[i] + 1)
        {
            dp[i * 2] = min(dp[i * 2], dp[i] + 1);
            p[i * 2] = i;
        }
        if (i * 3 <= n && dp[i * 3] > dp[i] + 1)
        {
            dp[i * 3] = min(dp[i * 3], dp[i] + 1);
            p[i * 3] = i;
        }
    }
    printf("%d\n", dp[n]);
    while (n != 1)
    {
        printf("%d ", n);
        n = p[n];
    }
    printf("1");
    return 0;
}

// int memo[1000001];

// int dp(int n)
// {
//     if (n == 1)
//         return 0;
//     int &ans = memo[n];
//     if (ans != -1)
//         return memo[n];

//     ans = dp(n - 1) + 1;
//     if (n % 3 == 0)
//         ans = min(ans, dp(n / 3) + 1);

//     if (n % 2 == 0)
//         ans = min(ans, dp(n / 2) + 1);

//     return ans;
// }

// void print_dp(int n)
// {

//     if (n == 1)
//     {
//         printf("1\n");
//         return;
//     }

//     if (dp(n - 1) + 1 == memo[n])
//     {
//         printf("%d ", n);
//         print_dp(n - 1);
//         return;
//     }

//     if (n % 3 == 0 and dp(n / 3) + 1 == memo[n])
//     {
//         printf("%d ", n);
//         print_dp(n / 3);
//         return;
//     }
//     if (n % 2 == 0 and dp(n / 2) + 1 == memo[n])
//     {
//         printf("%d ", n);
//         print_dp(n / 2);
//         return;
//     }
// }