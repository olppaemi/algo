// https://onlinejudge.org/external/102/10258.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (size_t i = 0; i < n; i++)
#define REPN(i, n) for (size_t i = 1; i <= n; i++)
#define FOR(i, a, b) for (size_t i = a; i < b; i++)
#define INF 1000000000
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX_C 101
#define MAX_P 10

bool cmp(const tuple<int, int, int> a, const tuple<int, int, int> b)
{
    if (get<0>(a) > get<0>(b))
        return true;
    else if (get<0>(a) == get<0>(b))
    {
        if (get<1>(a) < get<1>(b))
        {
            return true;
        }
        else if (get<1>(a) == get<1>(b))
        {
            return get<2>(a) < get<2>(b);
        }
    }
    return false;
}

int main()
{
    size_t tc;
    int contestant, problem, time;
    char L;
    string input;

    scanf(" %d ", &tc);
    REP(i, tc)
    {
        if (i)
            cout << '\n';
        vii scoreboard(MAX_C, {0, 0});
        int num_incorrect[MAX_C][MAX_P] = {0};
        int solved[MAX_C][MAX_P] = {0};
        bool participant[MAX_C] = {false};

        while (getline(cin, input), input != "")
        {
            istringstream iss(input);
            iss >> contestant >> problem >> time >> L;
            participant[contestant] = true;
            if (!solved[contestant][problem])
            {
                if (L == 'C')
                {
                    scoreboard[contestant].first++;
                    scoreboard[contestant].second += time + 20 * num_incorrect[contestant][problem];
                    solved[contestant][problem] = 1;
                }
                else if (L == 'I')
                {
                    num_incorrect[contestant][problem]++;
                }
            }
            input.clear();
        }
        vector<tuple<int, int, int>> answer;
        REP(i, MAX_C)
        {
            if (participant[i])
            {
                answer.push_back({scoreboard[i].first, scoreboard[i].second, i});
            }
        }
        sort(answer.begin(), answer.end(), cmp);
        for (auto &x : answer)
        {
            cout << get<2>(x) << ' ' << get<0>(x) << ' ' << get<1>(x) << '\n';
        }
    }

    return 0;
}