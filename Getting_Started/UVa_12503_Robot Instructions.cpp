// https://onlinejudge.org/external/125/12503.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INF 1000000000
typedef vector<int> vi;
typedef pair<int, int> ii;

int solution(int n, string commands[])
{
    int answer = 0;
    REP(i, n)
    {
        if (commands[i] == "LEFT")
            answer--;
        else if (commands[i] == "RIGHT")
            answer++;
    }
    return answer;
}

int main()
{
    int tc, n;
    string commands[100];

    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%d ", &n);
        REP(i, n)
        {
            getline(cin, commands[i]);

            if (commands[i][0] == 'S')
            {
                int num = stoi(commands[i].substr(8)) - 1;
                commands[i] = commands[num];
            }
        }
        printf("%d\n", solution(n, commands));
    }

    return 0;
}