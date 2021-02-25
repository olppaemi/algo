// https://onlinejudge.org/external/126/12696.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INF 1000000000
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{
    int tc;
    int allowed = 0;
    double length, width, depth, weight;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%lf %lf %lf %lf", &length, &width, &depth, &weight);
        if (((length <= 56.0 and width <= 45.0 and depth <= 25.0) or length + width + depth <= 125.0) and weight <= 7.0)
        {
            printf("1\n");
            allowed++;
        }
        else
            printf("0\n");
    }
    printf("%d\n", allowed);
    return 0;
}