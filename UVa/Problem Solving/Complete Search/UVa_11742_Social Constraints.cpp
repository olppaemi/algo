// https://onlinejudge.org/external/117/11742.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n, m;
    int a[20], b[20], c[20];

    while (scanf("%d %d", &n, &m), n || m)
    {
        int p[8] = {0, 1, 2, 3, 4, 5, 6, 7};
        int count = 0;

        REP(i, m)
        {
            scanf("%d %d %d", &a[i], &b[i], &c[i]);
        }

        do
        {
            bool flag = true;
            REP(i, m)
            {
                int x = find(p, p + n, a[i]) - p;
                int y = find(p, p + n, b[i]) - p;

                if (c[i] > 0 and abs(x - y) > c[i])
                {
                    flag = false;
                    break;
                }
                else if (c[i] < 0 and abs(x - y) < -c[i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                count++;
        } while (next_permutation(p, p + n));
        printf("%d\n", count);
    }

    return 0;
}