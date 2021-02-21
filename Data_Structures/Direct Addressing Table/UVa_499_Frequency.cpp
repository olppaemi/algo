// https://onlinejudge.org/external/4/499.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define RESET(a) memset(a, 0, sizeof(a))

int upper[26];
int lower[26];

int main()
{
    string line;
    int mx;
    while (getline(cin, line))
    {
        RESET(upper);
        RESET(lower);
        mx = 0;
        REP(i, line.length())
        {
            if (isupper(line[i]))
            {
                upper[line[i] - 'A']++;
                if (upper[line[i] - 'A'] > mx)
                    mx = upper[line[i] - 'A'];
            }
            else if (islower(line[i]))
            {
                lower[line[i] - 'a']++;
                if (lower[line[i] - 'a'] > mx)
                    mx = lower[line[i] - 'a'];
            }
        }
        REP(i, 26)
        {
            if (upper[i] == mx)
                cout << (char)(i + 'A');
        }
        REP(i, 26)
        {
            if (lower[i] == mx)
                cout << (char)(i + 'a');
        }
        cout << ' ' << mx << '\n';
    }

    return 0;
}