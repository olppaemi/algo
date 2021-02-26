// https://onlinejudge.org/external/131/13190.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
typedef tuple<int, int, int, string> iiis;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc, n, k, i, t;
    string name;
    int f;

    cin >> tc;
    while (tc--)
    {
        priority_queue<iiis, vector<iiis>, greater<iiis>> pq;
        cin >> n >> k;
        REP(i, n)
        {
            cin >> name >> f;
            pq.push({f, i, f, name});
        }

        while (k--)
        {
            tie(t, i, f, name) = pq.top();
            pq.pop();
            cout << t << ' ' << name << '\n';
            pq.push({t + f, i, f, name});
        }
    }

    return 0;
}