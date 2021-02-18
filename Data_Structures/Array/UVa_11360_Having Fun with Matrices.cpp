// https://onlinejudge.org/external/113/11360.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)

int n;
int matrix[10][10];

void transpose()
{

    FOR(i, 1, n)
    {
        REP(j, i)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
void inc()
{
    REP(i, n)
    {
        REP(j, n)
        {
            matrix[i][j]++;
            if (matrix[i][j] >= 10)
                matrix[i][j] = 0;
        }
    }
}
void dec()
{
    REP(i, n)
    {
        REP(j, n)
        {
            matrix[i][j]--;
            if (matrix[i][j] < 0)
                matrix[i][j] = 9;
        }
    }
}
void row(int a, int b)
{
    REP(i, n)
    {
        swap(matrix[a][i], matrix[b][i]);
    }
}
void col(int a, int b)
{
    REP(i, n)
    {
        swap(matrix[i][a], matrix[i][b]);
    }
}

int main()
{
    int tc;
    char op[15];
    int m, a, b;

    scanf("%d", &tc);
    REPN(test_case, tc)
    {

        printf("Case #%d\n", test_case);
        scanf("%d", &n);
        REP(i, n)
        {
            REP(j, n)
            {
                scanf("%1d", &matrix[i][j]);
            }
        }
        scanf("%d", &m);
        REP(i, m)
        {
            scanf("%s", op);
            if (!strcmp(op, "transpose"))
                transpose();
            else if (!strcmp(op, "inc"))
                inc();
            else if (!strcmp(op, "dec"))
                dec();
            else
            {
                scanf("%d %d", &a, &b);
                a--, b--;
                if (!strcmp(op, "row"))
                    row(a, b);
                else
                    col(a, b);
            }
        }
        REP(i, n)
        {
            REP(j, n)
            {
                printf("%d", matrix[i][j]);
            }
            puts("");
        }
        puts("");
    }
}