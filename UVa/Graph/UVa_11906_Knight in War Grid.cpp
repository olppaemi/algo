// https://onlinejudge.org/external/119/11906.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

int grid[100][100];
bool visited[100][100];
int r, c, m, n;

pair<int, int> bfs()
{
    int dx[] = {m, -m, m, -m, n, -n, n, -n};
    int dy[] = {n, n, -n, -n, m, m, -m, -m};
    int x, y;
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = 1;
    while (!q.empty())
    {

        tie(x, y) = q.front();
        q.pop();
        set<pair<int, int>> adj;
        REP(i, 8)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 and nx < r and ny >= 0 and ny < c and grid[nx][ny] != -1)
                adj.insert({nx, ny});
        }
        for (auto &[x, y] : adj)
        {
            ++grid[x][y];
            if (!visited[x][y])
            {
                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }
    int even, odd;
    even = odd = 0;
    REP(i, r)
    {
        REP(j, c)
        {
            if ((grid[i][j] != -1 and grid[i][j] != 0) || (i == 0 and j == 0))
            {
                if (grid[i][j] & 1)
                    ++odd;
                else
                    ++even;
            }
        }
    }
    return {even, odd};
}

int main()
{    
    int tc;
    int w, x, y;

    scanf("%d", &tc);

    REPN(test_case, tc)
    {
        RESET(grid, 0);
        RESET(visited, false);
        scanf("%d %d %d %d %d", &r, &c, &m, &n, &w);
        REP(i, w)
        {
            scanf("%d %d", &x, &y);
            grid[x][y] = -1;
        }

        pair<int, int> ans = bfs();
        printf("Case %d: %d %d\n", test_case, ans.first, ans.second);
    }

    return 0;
}