// https://onlinejudge.org/external/10/1062.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)

int solution(size_t n, char containers[])
{
    vector<stack<char>> vs;
    stack<char> s;
    bool done;

    s.push(containers[0]);
    vs.push_back(s);
    s.pop();
    FOR(i, 1, n)
    {
        done = false;
        REP(j, vs.size())
        {
            if (containers[i] <= vs[j].top())
            {
                vs[j].push(containers[i]);
                done = true;
                break;
            }
        }
        if (!done)
        {
            s.push(containers[i]);
            vs.push_back(s);
            s.pop();
        }
    }
    return vs.size();
}

int main()
{
    char containers[1001];
    int tc = 1;
    while (scanf("%s", containers), strcmp(containers, "end"))
    {
        printf("Case %d: %d\n", tc++, solution(strlen(containers), containers));
    }
    return 0;
}