// https://onlinejudge.org/external/115/11559.pdf

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
    int n, b, h, w;

    while (scanf("%d %d %d %d", &n, &b, &h, &w) == 4)
    {
        int price, available;
        int answer = INF;
        REP(i, h)
        {
            scanf("%d", &price);
            REP(j, w)
            {
                scanf("%d", &available);
                if (available >= n and price * n < answer)
                    answer = price * n;
            }
        }
        if (answer <= b)
            printf("%d\n", answer);
        else
            printf("stay home\n");
    }
    return 0;
}