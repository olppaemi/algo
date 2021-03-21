// https://onlinejudge.org/external/8/821.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)
#define INF 1061109567

int AM[101][101];

int main()
{
    int tc = 0;
    string line;
    while (getline(cin, line), line != "0 0")
    {
        istringstream iss(line);
        int u, v;
        int n = 0;

        memset(AM, 63, sizeof(AM));
        while (iss >> u >> v, u | v)
        {
            AM[u][v] = 1;
            n = max(n, max(u, v));
        }

        REPN(k, n)
        {
            REPN(i, n)
            {
                REPN(j, n)
                {
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                }
            }
        }

        int sum = 0, count = 0;
        REPN(i, n)
        {
            REPN(j, n)
            {
                if (i != j and AM[i][j] != INF)
                {
                    sum += AM[i][j];
                    ++count;
                }
            }
        }

        printf("Case %d: average length between pages = %.3f clicks\n", ++tc, (double)sum / count);
    }

    return 0;
}