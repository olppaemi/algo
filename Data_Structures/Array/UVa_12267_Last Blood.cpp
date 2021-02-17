// https://onlinejudge.org/external/126/12667.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

#define MAX_N 12 + 4
#define MAX_T 100 + 26
#define MAX_M 1000 + 24

int main()
{
    int n, t, m;
    int time, team_id;
    char problem, verdict[10];

    int scoreboard[MAX_T + 1][MAX_N] = {};
    int ans_time[MAX_N], ans_team[MAX_N];
    memset(ans_time, -1, sizeof(ans_time));

    scanf("%d %d %d", &n, &t, &m);
    REP(i, m)
    {
        scanf("%d %d %c %s ", &time, &team_id, &problem, verdict);
        if (verdict[0] == 'Y')
        {
            int p = problem - 'A';
            if (scoreboard[team_id][p] == 0)
            {
                scoreboard[team_id][p] = 1;
                ans_time[p] = time;
                ans_team[p] = team_id;
            }
        }
    }
    REP(i, n)
    {
        printf("%c ", 'A' + i);
        if (ans_time[i] != -1)
            printf("%d %d\n", ans_time[i], ans_team[i]);
        else
            printf("- -\n");
    }

    return 0;
}