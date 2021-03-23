#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, -1, 0, 1, 1, -1, 1, -1};

int main()
{
    int field = 0;
    int n, m;
    char square[100][101];

    while (scanf("%d %d", &n, &m), n | m)
    {
        REP(i, n)
        {
            scanf("%s", square[i]);
        }
        REP(x, n)
        {
            REP(y, m)
            {
                if (square[x][y] == '.')
                {
                    int count = 0;
                    REP(i, 8)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if (nx < 0 or nx >= n or ny < 0 or ny >= m)
                            continue;
                        if (square[nx][ny] == '*')
                            ++count;
                    }
                    square[x][y] = count + '0';
                }
            }
        }

        if (field)
            puts("");
        printf("Field #%d:\n", ++field);
        REP(i, n)
        {
            printf("%s\n", square[i]);
        }
    }

    return 0;
}