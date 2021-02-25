// https://uhunt.onlinejudge.org/id/1137188

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (size_t i = 0; i < n; i++)
#define FOR(i, a, b) for (size_t i = a; i < b; i++)

int main()
{
    size_t n;
    string s;

    while (cin >> n, n)
    {
        vector<string> names;
        REP(i, n)
        {
            cin >> s;
            names.push_back(s);
        }
        sort(names.begin(), names.end());
        string answer;
        string p = names[n / 2 - 1], q = names[n / 2];

        if (p.length() < q.length())
        {
            REP(i, p.length())
            {
                if (p[i] == q[i] || i == p.length() - 1)
                    answer += p[i];
                else
                {
                    answer += p[i] + 1;
                    break;
                }
            }
        }
        else
        {
            REP(i, q.length())
            {
                if (p[i] == q[i])
                    answer += p[i];
                else if (i == q.length() - 1)
                {
                    if (i == p.length() - 1)
                    {
                        answer += p[i];
                        break;
                    }
                    if (p[i] + 1 != q[i])
                    {
                        answer += p[i] + 1;
                        break;
                    }
                    else
                    {
                        answer += p[i];
                        FOR(j, i + 1, p.length())
                        {
                            if (j == p.length() - 1)
                                answer += p[j];
                            else if (p[j] != 'Z')
                            {
                                answer += p[j] + 1;
                                break;
                            }
                            else
                                answer += p[j];
                        }
                    }
                }
                else
                {
                    answer += p[i] + 1;
                    break;
                }
            }
        }
        cout << answer << '\n';
    }

    return 0;
}