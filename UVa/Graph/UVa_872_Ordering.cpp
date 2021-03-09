// https://onlinejudge.org/external/8/872.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define RESET(a, b) memset(a, b, sizeof(a))

int graph[26][26], used[26], n;
char ans[26];
bool ordering;
string variables, constraints;

void dfs(int idx)
{
    if (idx == n)
    {
        ordering = true;
        REP(i, n)
        {
            cout << ans[i] << " \n"[i == (n - 1)];
        }
        return;
    }
    REP(i, n)
    {
        if (used[i] == 0)
        {
            int j = 0;
            for (; j < idx; ++j)
                if (graph[variables[i] - 'A'][ans[j] - 'A'] == 1)
                    break;
            if (j == idx)
            {
                used[i] = 1;
                ans[idx] = variables[i];
                dfs(idx + 1);
                used[i] = 0;
            }
        }
    }
}

int main()
{
    int tc;
    string line, line2, var, con;

    cin >> tc;
    cin.ignore();
    while (tc--)
    {
        RESET(graph, 0);
        RESET(used, 0);
        ordering = false;
        getline(cin, line);
        getline(cin, line);
        getline(cin, line2);
        stringstream ss;
        ss << line;
        variables = "";

        while (ss >> var)
        {
            variables += var;
            ++n;
        }
        n = variables.size();
        sort(variables.begin(), variables.end());
        ss.clear();
        ss << line2;
        while (ss >> con)
        {
            assert(con.size() == 3);
            graph[con[0] - 'A'][con[2] - 'A'] = 1;
        }
        dfs(0);
        if (!ordering)
            cout << "NO\n";

        if (tc)
            cout << '\n';
    }
    return 0;
}