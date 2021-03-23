#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int tc;
    int a, b, c;

    scanf("%d", &tc);
    while (tc--)
    {
        int ladder[101] = {}, snake[101] = {};
        scanf("%d %d %d", &a, &b, &c);
        int x, y;
        REP(i, b)
        {
            scanf("%d %d", &x, &y);
            if (x < y)
                ladder[x] = y;
            else
                snake[x] = y;
        }
        int die, player = 0;
        bool gameover = false;
        vector<int> position(a, 1);

        REP(i, c)
        {
            scanf("%d", &die);
            if (a and !gameover)
            {
                position[player] += die;
                if (ladder[position[player]])
                {
                    position[player] = ladder[position[player]];
                }
                else if (snake[position[player]])
                {
                    position[player] = snake[position[player]];
                }
                if (position[player] >= 100)
                {
                    position[player] = 100;
                    gameover = true;
                }
                player = (player + 1) % a;
            }
        }

        REP(i, a)
        {
            printf("Position of player %d is %d.\n", i + 1, position[i]);
        }
    }

    return 0;
}