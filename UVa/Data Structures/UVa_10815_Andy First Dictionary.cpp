// https://onlinejudge.org/external/108/10815.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line, word;
    set<string> dict;
    while (getline(cin, line))
    {
        if (line.length() == 0)
            continue;
        for (auto &c : line)
            if (!isalpha(c))
                c = ' ';
            else
            {
                c = tolower(c);
            }

        istringstream iss(line);
        while (iss >> word)
            dict.insert(word);
    }

    for (auto &word : dict)
    {
        cout << word << '\n';
    }

    return 0;
}