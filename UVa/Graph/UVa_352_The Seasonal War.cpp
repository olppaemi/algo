// https://onlinejudge.org/external/3/352.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

int n;
int image[25][25];
bool visited[25][25];

int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};

void dfs(int x, int y)
{
    visited[x][y] = 1;
    REP(i, 8)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 or nx >= n or ny < 0 or ny >= n or !image[nx][ny])
            continue;
        if (!visited[nx][ny])
            dfs(nx, ny);
    }
}

int main()
{
    int tc = 0;
    while (scanf("%d", &n) != EOF)
    {
        RESET(image, 0);
        RESET(visited, 0);
        REP(i, n)
        {
            REP(j, n)
            {
                scanf("%1d", &image[i][j]);
            }
        }

        int cc = 0;
        REP(i, n)
        {
            REP(j, n)
            {
                if (image[i][j] and !visited[i][j])
                {
                    dfs(i, j);
                    ++cc;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", ++tc, cc);
    }

    return 0;
}