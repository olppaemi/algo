#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n, m;
    int dragon[20000], knight[20000];
    int d, k, gold;

    while (scanf("%d %d", &n, &m), n || m)
    {
        REP(i, n)
        {
            scanf("%d", &dragon[i]);
        }
        REP(i, m)
        {
            scanf("%d", &knight[i]);
        }
        sort(dragon, dragon + n);
        sort(knight, knight + m);

        gold = d = k = 0;
        while (d < n and k < m)
        {
            while (k < m and dragon[d] > knight[k])
                ++k;
            if (k == m)
                break;
            gold += knight[k];
            ++d;
            ++k;
        }
        (d == n) ? printf("%d\n", gold) : printf("Loowater is doomed!\n");
    }
    return 0;
}