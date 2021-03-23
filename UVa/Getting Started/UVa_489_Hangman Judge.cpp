#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int round;
    string puzzle, guess;

    while (scanf("%d", &round), round != -1)
    {
        cin >> puzzle >> guess;
        bool used[26] = {}, ans[26] = {};
        int count = 0;
        for (auto x : puzzle)
        {
            if (!used[x - 'a'])
            {
                used[x - 'a'] = true;
                ++count;
            }
            if (count == 26)
                break;
        }

        int stroke = 0;
        REP(i, guess.length())
        {
            int tmp = guess[i] - 'a';
            if (!ans[tmp])
            {
                ans[tmp] = true;
                if (used[tmp])
                {
                    used[tmp] = false;
                    --count;
                }
                else
                    ++stroke;
            }

            if (stroke > 6 or !count)
                break;
        }

        printf("Round %d\n", round);
        if (stroke == 7)
            puts("You lose.");
        else if (count)
            puts("You chickened out.");
        else
            puts("You win.");
    }
    return 0;
}