// https://onlinejudge.org/external/115/11550.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int mat[n][m];
        REP(i, n)
        {
            REP(j, m)
            {
                scanf("%d", &mat[i][j]);
            }
        }

        bool flag = true;
        set<string> ss;
        REP(j, m)
        {
            int sum = 0;
            string s = "";
            REP(i, n)
            {
                sum += mat[i][j];
                if (mat[i][j])
                {
                    s += (i + '0');
                }
            }
            if (sum != 2 or s.length() != 2 or ss.find(s) != ss.end())
            {
                flag = false;
                break;
            }
            ss.insert(s);
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}