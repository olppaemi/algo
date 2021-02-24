// https://onlinejudge.org/external/108/10895.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

int main()
{
    int r, c, n, x;
    while (scanf("%d %d", &r, &c) != EOF)
    {
        vector<vector<pair<int, int>>> matrix(r + 1), matrixT(c + 1);

        REPN(i, r)
        {
            scanf("%d", &n);
            int place[n];
            REP(j, n)
            {
                scanf("%d", &place[j]);
            }
            REP(j, n)
            {
                scanf("%d", &x);
                matrix[i].push_back({place[j], x});
            }
        }

        REPN(i, r)
        {
            REP(j, matrix[i].size())
            {
                int col = matrix[i][j].first;
                int val = matrix[i][j].second;
                matrixT[col].push_back({i, val});
            }
        }

        printf("%d %d\n", c, r);
        REPN(i, c)
        {
            printf("%d", matrixT[i].size());
            REP(j, matrixT[i].size())
            {
                printf(" %d", matrixT[i][j].first);
            }
            puts("");
            REP(j, matrixT[i].size())
            {
                if (j == matrixT[i].size() - 1)
                    printf("%d", matrixT[i][j].second);
                else
                    printf("%d ", matrixT[i][j].second);
            }
            puts("");
        }
    }

    return 0;
}