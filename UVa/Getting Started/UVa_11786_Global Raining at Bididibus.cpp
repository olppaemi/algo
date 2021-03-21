#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

int solution(string &str)
{
    int answer = 0;
    stack<int> s;

    REP(i, str.length())
    {
        if (str[i] == '\\')
            s.push(i);
        else if (str[i] == '/' and !s.empty())
        {
            answer += i - s.top();
            s.pop();
        }
    }
    return answer;
}

int main()
{
    int tc;
    string str;

    cin >> tc;
    while (tc--)
    {
        cin >> str;
        cout << solution(str) << '\n';
    }

    return 0;
}