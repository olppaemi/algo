// https://onlinejudge.org/external/5/572.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

char grid[100][100];
bool visited[100][100];
int m, n;

int dx[] = {0, 1, 0, -1, -1, -1, 1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};

int main()
{
    while (scanf("%d %d", &m, &n), m)
    {
        RESET(visited, false);
        REP(i, m)
        {
            REP(j, n)
            {
                scanf(" %c", &grid[i][j]);
            }
        }

        queue<pair<int, int>> q;
        int ans = 0;
        REP(i, m)
        {
            REP(j, n)
            {
                if (grid[i][j] == '@' and !visited[i][j])
                {
                    ++ans;
                    q.push({i, j});
                    visited[i][j] = true;
                    while (!q.empty())
                    {
                        int x, y;
                        tie(x, y) = q.front();
                        q.pop();

                        REP(k, 8)
                        {
                            int nx = x + dx[k], ny = y + dy[k];
                            if (nx < 0 or nx >= m or ny < 0 or ny >= n or grid[x][y] == '*')
                                continue;
                            if (!visited[nx][ny])
                            {
                                q.push({nx, ny});
                                visited[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}