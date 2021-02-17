// https://onlinejudge.org/external/115/11581.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

bool check(int g[][3])
{
    REP(i, 3)
    {
        REP(j, 3)
        {
            if (g[i][j])
                return false;
        }
    }
    return true;
}

void f(int g[][3])
{
    int t[3][3] = {0};
    int nx, ny;

    REP(i, 3)
    {
        REP(j, 3)
        {
            REP(k, 4)
            {
                nx = i + dx[k];
                ny = j + dy[k];
                if (nx < 0 or nx > 2 or ny < 0 or ny > 2)
                    continue;
                t[i][j] += g[nx][ny];
                t[i][j] %= 2;
            }
        }
    }
    REP(i, 3)
    {
        REP(j, 3)
        {
            g[i][j] = t[i][j];
        }
    }
}

int solution(int g[][3])
{
    int answer = -1;
    while (!check(g))
    {
        answer++;
        f(g);
    }
    return answer;
}

int main()
{
    int tc;
    int g[3][3];
    scanf("%d", &tc);
    while (tc--)
    {
        REP(i, 3)
        {
            REP(j, 3)
            {
                scanf("%1d", &g[i][j]);
            }
        }
        printf("%d\n", solution(g));
    }
    return 0;
}