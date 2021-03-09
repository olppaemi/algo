// https://onlinejudge.org/external/110/11060.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int tc = 0, n, m;
    string s1, s2;

    while (cin >> n)
    {
        vector<vector<int>> adj_list(n);
        map<string, int> name_to_id;
        map<int, string> id_to_name;
        vector<int> indegree(n);
        vector<int> ts;
        int id = 0;

        REP(i, n)
        {
            cin >> s1;
            if (name_to_id.find(s1) == name_to_id.end())
            {
                id_to_name[id] = s1;
                name_to_id[s1] = id++;
            }
        }
        cin >> m;
        REP(i, m)
        {
            cin >> s1 >> s2;
            int u = name_to_id[s1], v = name_to_id[s2];
            adj_list[u].push_back(v);
            ++indegree[v];
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        REP(i, n)
        {
            if (indegree[i] == 0)
                pq.push(i);
        }

        while (!pq.empty())
        {
            int u = pq.top();
            pq.pop();
            ts.push_back(u);

            for (auto &v : adj_list[u])
            {
                --indegree[v];
                if (indegree[v] == 0)
                    pq.push(v);
            }
        }

        cout << "Case #" << ++tc << ": Dilbert should drink beverages in this order: ";
        REP(i, n - 1)
        {
            cout << id_to_name[ts[i]] << ' ';
        }
        cout << id_to_name[ts[n - 1]] << ".\n\n";
    }

    return 0;
}