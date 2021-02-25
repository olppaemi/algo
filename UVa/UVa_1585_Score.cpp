// https://onlinejudge.org/external/15/1585.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INF 1000000000
typedef vector<int> vi;
typedef tuple<int, int> ii;

int main()
{
    int tc;
    char s[80];
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%s", s);
        int answer = 0;
        int score = 1;
        bool consecutive = false;
        REP(i, strlen(s))
        {
            if (s[i] == 'O')
            {
                if (consecutive)
                    answer += score++;
                else
                {
                    score = 1;
                    answer += score++;
                    consecutive = true;
                }
            }
            else
                consecutive = false;
        }
        printf("%d\n", answer);
    }
    return 0;
}