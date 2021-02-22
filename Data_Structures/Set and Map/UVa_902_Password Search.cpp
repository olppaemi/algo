// https://onlinejudge.org/external/9/902.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n, mx;
    string password;
    map<string, int> ans;

    while (cin >> n >> password)
    {

        REP(i, password.size() - n + 1)
        {
            ans[password.substr(i, n)]++;
        }

        mx = 0;
        for (auto &x : ans)
        {
            if (x.second > mx)
            {
                password = x.first;
                mx = x.second;
            }
        }
        cout << password << '\n';
        ans.clear();
    }
    return 0;
}