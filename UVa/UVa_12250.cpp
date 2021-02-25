// https://onlinejudge.org/external/122/12250.pdf

#include <bits/stdc++.h>

using namespace std;

string solution(string s)
{
    if (s == "HELLO")
        return "ENGLISH";
    else if (s == "HOLA")
        return "SPANISH";
    else if (s == "HALLO")
        return "GERMAN";
    else if (s == "BONJOUR")
        return "FRENCH";
    else if (s == "CIAO")
        return "ITALIAN";
    else if (s == "ZDRAVSTVUJTE")
        return "RUSSIAN";
    else
        return "UNKNOWN";
}

int main()
{
    string s;
    int tc = 1;
    while (1)
    {
        cin >> s;
        if (s == "#")
            break;
        cout << "Case " << tc++ << ": " << solution(s) << '\n';
    }

    return 0;
}