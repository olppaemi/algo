// https://onlinejudge.org/external/121/12187.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int n, r, c, k;
int kingdom[100][100];
int attack[100][100];

void battle()
{
    int nx, ny;
    memset(attack, -1, sizeof(attack));

    REP(i, r)
    {
        REP(j, c)
        {
            REP(k, 4)
            {
                nx = i + dx[k];
                ny = j + dy[k];
                if (nx < 0 or nx >= r or ny < 0 or ny >= c or kingdom[nx][ny] != (kingdom[i][j] + 1) % n)
                    continue;
                attack[nx][ny] = kingdom[i][j];
            }
        }
    }

    REP(i, r)
    {
        REP(j, c)
        {
            if (attack[i][j] != -1)
                kingdom[i][j] = attack[i][j];
        }
    }
}

int main()
{
    while (scanf("%d %d %d %d", &n, &r, &c, &k), n || r || c || k)
    {
        REP(i, r)
        {
            REP(j, c)
            {
                scanf("%d", &kingdom[i][j]);
            }
        }
        while (k--)
            battle();

        REP(i, r)
        {
            REP(j, c)
            {
                j != c - 1 ? printf("%d ", kingdom[i][j]) : printf("%d\n", kingdom[i][j]);
            }
        }
    }

    return 0;
}