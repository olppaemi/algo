// https://onlinejudge.org/external/119/11997.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

vi merge(const vi &a, const vi &b)
{
    vi res;
    priority_queue<ii, vii, greater<ii>> pq;
    REP(i, a.size())
    {
        pq.push({a[i] + b[0], 0});
    }

    while (res.size() < a.size())
    {
        int sum, bid;
        tie(sum, bid) = pq.top();
        pq.pop();
        res.push_back(sum);
        if (bid + 1 < b.size())
            pq.push({sum - b[bid] + b[bid + 1], bid + 1});
    }
    return res;
}

vi solution(int n, vvi a)
{
    REP(i, n)
    {
        sort(a[i].begin(), a[i].end());
    }

    vi cur = a[0];
    FOR(i, 1, n)
    {
        cur = merge(cur, a[i]);
    }
    return cur;
}

int main()
{
    int k;

    while (scanf("%d", &k) != EOF)
    {
        vvi a(k, vi(k));
        REP(i, k)
        {
            REP(j, k)
            {
                scanf("%d", &a[i][j]);
            }
        }
        vi answer = solution(k, a);
        REP(i, answer.size())
        {
            if (i != answer.size() - 1)
                printf("%d ", answer[i]);
            else
                printf("%d\n", answer[i]);
        }
    }

    return 0;
}