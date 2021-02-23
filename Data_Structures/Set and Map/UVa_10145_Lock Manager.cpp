// https://onlinejudge.org/external/101/10145.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define CONTAINS(v, x) (find(ALL(v), x) != v.end())

void solution(const vector<tuple<char, int, int>> &request)
{
    enum
    {
        FREE,
        SHARED,
        EXCLUSIVE
    };
    set<int> blocked;
    map<int, pair<int, int>> lock_state;
    map<int, vector<int>> tid_locks;

    for (auto &[mode, tid, item] : request)
    {
        if (blocked.count(tid))
        {
            printf("IGNORED\n");
        }
        else if (mode == 'S')
        {
            if (lock_state[item].first == FREE or lock_state[item].first == SHARED)
            {
                printf("GRANTED\n");
                lock_state[item].first = SHARED;
                if (!CONTAINS(tid_locks[tid], item))
                {
                    lock_state[item].second++;
                    tid_locks[tid].push_back(item);
                }
            }
            else if (lock_state[item].first == EXCLUSIVE)
            {
                if (lock_state[item].second == tid)
                {
                    printf("GRANTED\n");
                }
                else
                {
                    printf("DENIED\n");
                    blocked.insert(tid);
                }
            }
        }
        else if (mode == 'X')
        {
            if (lock_state[item].first == SHARED and lock_state[item].second == 1)
            {
                if (CONTAINS(tid_locks[tid], item))
                {
                    printf("GRANTED\n");
                    lock_state[item].first = EXCLUSIVE;
                    lock_state[item].second = tid;
                }
                else
                {
                    printf("DENIED\n");
                    blocked.insert(tid);
                }
            }
            else if (lock_state[item].first == FREE)
            {
                printf("GRANTED\n");
                lock_state[item].first = EXCLUSIVE;
                lock_state[item].second = tid;
            }
            else if (lock_state[item].first == EXCLUSIVE and lock_state[item].second == tid)
            {
                printf("GRANTED\n");
            }
            else
            {
                printf("DENIED\n");
                blocked.insert(tid);
            }
        }
    }
}

int main()
{
    int tc;
    char line[32];
    char mode;
    int trid, item;

    scanf("%d", &tc);
    getchar();
    REP(i, tc)
    {
        if (i)
            puts("");
        vector<tuple<char, int, int>> request;

        while (gets(line), line[0] != '#')
        {
            if (line[0] == '\0')
                continue;
            sscanf(line, "%c %d %d", &mode, &trid, &item);
            request.push_back({mode, trid, item});
        }
        solution(request);
    }

    return 0;
}