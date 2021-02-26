#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)

const int MAX = 500;

int solution(int l, int u, int n, int m, int height[][MAX])
{
    int best_size = 0;
    REP(row, n)
    {
        int col = lower_bound(height[row], height[row] + m, l) - height[row];
        if (col == m or height[row][col] < l)
            continue;
        FOR(size, best_size, n)
        {
            int end_row = row + size;
            int end_col = col + size;
            if (end_row >= n or end_col >= m or height[end_row][end_col] > u)
                break;
            if (size + 1 > best_size)
                best_size = size + 1;
        }
    }
    return best_size;
}

int main()
{
    int height[MAX][MAX];
    int n, m, q;
    int l, u;

    while (scanf("%d %d", &n, &m), n || m)
    {
        REP(i, n)
        {
            REP(j, m)
            {
                scanf("%d", &height[i][j]);
            }
        }

        scanf("%d", &q);
        REP(i, q)
        {
            scanf("%d %d", &l, &u);
            printf("%d\n", solution(l, u, n, m, height));
        }
        printf("-\n");
    }

    return 0;
}