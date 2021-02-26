// https://onlinejudge.org/external/6/612.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INF 1000000000
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int isort(const string a)
{
    string t = a;
    int num_inversions = 0;
    char key;
    int i;
    FOR(j, 1, t.length())
    {
        key = a[j];
        i = j - 1;
        while (i >= 0 and t[i] > key)
        {
            t[i + 1] = t[i];
            num_inversions++;
            i--;
        }
        t[i + 1] = key;
    }
    return num_inversions;
}

int main()
{
    int tc;
    int n, m;
    vector<tuple<int, int, string>> a(105);
    string x;

    cin >> tc;
    REP(i, tc)
    {
        cin >> n >> m;
        REP(i, m)
        {
            cin >> x;
            a[i] = {isort(x), i, x};
        }
        sort(a.begin(), a.begin() + m);
        REP(i, m)
        {
            cout << get<2>(a[i]) << '\n';
        }
        if (i != tc - 1)
            cout << '\n';
    }

    return 0;
}