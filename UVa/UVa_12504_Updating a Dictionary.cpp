// https://onlinejudge.org/external/125/12504.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))

void solution(map<string, string> &old_dict, map<string, string> &new_dict)
{
    vector<string> new_key, removed_key, changed_key;

    for (auto &x : new_dict)
    {
        if (old_dict.count(x.first) == 0)
            new_key.push_back(x.first);
        else if (old_dict[x.first] != x.second)
        {
            changed_key.push_back(x.first);
        }
    }

    for (auto &x : old_dict)
    {
        if (new_dict.count(x.first) == 0)
            removed_key.push_back(x.first);
    }

    SORT(new_key);
    SORT(removed_key);
    SORT(changed_key);

    if (new_key.empty() and removed_key.empty() and changed_key.empty())
    {
        cout << "No changes\n";
    }
    else
    {
        if (!new_key.empty())
        {
            cout << '+';
            for (auto it = new_key.begin(); it != (new_key.end() - 1); it++)
            {
                cout << *it << ',';
            }
            cout << *(--new_key.end()) << '\n';
        }
        if (!removed_key.empty())
        {
            cout << '-';
            for (auto it = removed_key.begin(); it != (removed_key.end() - 1); it++)
            {
                cout << *it << ',';
            }
            cout << *(--removed_key.end()) << '\n';
        }
        if (!changed_key.empty())
        {
            cout << '*';
            for (auto it = changed_key.begin(); it != (changed_key.end() - 1); it++)
            {
                cout << *it << ',';
            }
            cout << *(--changed_key.end()) << '\n';
        }
    }
}

int main()
{
    int tc;
    string line[2];
    string key, value;

    cin >> tc;
    while (tc--)
    {
        cin >> line[0] >> line[1];
        REP(i, 2)
        {
            for (auto &c : line[i])
                if (!isalnum(c))
                    c = ' ';
        }

        map<string, string> old_dict, new_dict;
        istringstream iss(line[0]), iss2(line[1]);

        while (iss >> key >> value)
            old_dict[key] = value;
        while (iss2 >> key >> value)
            new_dict[key] = value;

        solution(old_dict, new_dict);
        cout << '\n';
    }

    return 0;
}