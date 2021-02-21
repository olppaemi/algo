#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string query, x;
    stack<string> s;

    cin >> n;
    while (n--)
    {
        cin >> query;
        if (query == "Sleep")
        {
            cin >> x;
            s.push(x);
        }
        else if (query == "Kick")
        {
            if (s.size() > 0)
                s.pop();
        }
        else if (query == "Test")
        {
            s.size() > 0 ? cout << s.top() << '\n' : cout << "Not in a dream\n";
        }
    }
    return 0;
}