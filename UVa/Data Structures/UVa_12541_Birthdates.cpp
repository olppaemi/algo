// https://onlinejudge.org/external/125/12541.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n;
    vector<tuple<int, int, int, string>> people;

    cin >> n;
    people.resize(n);
    REP(i, n)
    {
        cin >> get<3>(people[i]) >> get<2>(people[i]) >> get<1>(people[i]) >> get<0>(people[i]);
    }
    sort(people.begin(), people.end());
    cout << get<3>(people[n - 1]) << '\n'
         << get<3>(people[0]) << '\n';

    return 0;
}