// https://onlinejudge.org/external/101/10116.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

int main()
{
    int r, c, e;
    while (scanf("%d %d %d", &r, &c, &e), r | c | e)
    {
        char grid[r][c];
        int num[r][c];
        RESET(num, -1);

        REP(i, r)
        {
            REP(j, c)
            {
                scanf(" %c", &grid[i][j]);
            }
        }
        int cur_x = 0, cur_y = e - 1;
        int step = 0;
        num[cur_x][cur_y] = step;
        while (1)
        {
            ++step;
            if (grid[cur_x][cur_y] == 'N')
                --cur_x;
            else if (grid[cur_x][cur_y] == 'S')
                ++cur_x;
            else if (grid[cur_x][cur_y] == 'W')
                --cur_y;
            else if (grid[cur_x][cur_y] == 'E')
                ++cur_y;

            if (cur_x < 0 or cur_x >= r or cur_y < 0 or cur_y >= c)
            {
                printf("%d step(s) to exit\n", step);
                break;
            }

            if (num[cur_x][cur_y] != -1)
            {
                printf("%d step(s) before a loop of %d step(s)\n", num[cur_x][cur_y], step - num[cur_x][cur_y]);
                break;
            }
            num[cur_x][cur_y] = step;
        }
    }

    return 0;
}