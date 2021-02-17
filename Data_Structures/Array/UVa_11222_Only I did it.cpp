// https://onlinejudge.org/external/112/11222.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

int main()
{
    int tc;
    scanf("%d", &tc);
    REPN(test_case, tc)
    {
        bool s[3][10001] = {false};
        int c, v, count[3] = {0};
        int p[3][1000];

        REP(i, 3)
        {
            scanf("%d", &c);
            REP(j, c)
            {
                scanf("%d", &v);
                if (s[i][v] == false)
                {
                    s[i][v] = true;
                    p[i][count[i]++] = v;
                }
            }
        }

        int u_c[3] = {0};
        int u[3][1000];
        int m = 0;
        int sol[4] = {0};

        REP(i, 3)
        {
            REP(j, count[i])
            {
                int problem = p[i][j];
                bool unique = !s[(i + 1) % 3][problem] & !s[(i + 2) % 3][problem];
                if (unique)
                    u[i][u_c[i]++] = problem;
            }
            if (sol[0] == 0 || u_c[i] > u_c[m])
            {
                m = i;
                sol[0] = 1;
                sol[1] = m;
            }
            else if (u_c[i] == u_c[m])
            {
                sol[++sol[0]] = i;
            }
        }

        printf("Case #%d:\n", test_case);
        REPN(i, sol[0])
        {
            m = sol[i];
            printf("%d %d", m + 1, u_c[m]);
            sort(u[m], u[m] + u_c[m]);
            REP(j, u_c[m])
            {
                printf(" %d", u[m][j]);
            }
            puts("");
        }
    }
    return 0;
}