#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define RESET(a, b) memset(a, b, sizeof(a))

int parent[26];

int find(int u)
{
    if (parent[u] >= 0)
    {
        parent[u] = find(parent[u]);
        return parent[u];
    }
    return u;
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        int tmp = parent[u] + parent[v];
        if (-parent[u] < -parent[v])
        {
            parent[u] = v;
            parent[v] = tmp;
        }
        else
        {
            parent[v] = u;
            parent[u] = tmp;
        }
    }
}

int main()
{
    int tc;
    string line;

    cin >> tc;
    while (tc--)
    {
        RESET(parent, -1);
        map<char, int> code;
        int num = 0;

        cin.ignore();
        while (getline(cin, line), line[0] != '*')
        {
            char u = line[1], v = line[3];
            if (!code.count(u))
                code[u] = num++;

            if (!code.count(v))
                code[v] = num++;

            merge(code[u], code[v]);
        }

        cin >> line;
        for (int i = 0; i < line.length(); i += 2)
        {
            if (!code.count(line[i]))
                code[line[i]] = num++;
        }

        int num_tree = 0, num_acorn = 0;
        REP(i, num)
        {
            if (parent[i] == -1)
                num_acorn++;
            else if (parent[i] < -1)
                num_tree++;
        }
        cout << "There are " << num_tree << " tree(s) and " << num_acorn << " acorn(s).\n";
    }

    return 0;
}