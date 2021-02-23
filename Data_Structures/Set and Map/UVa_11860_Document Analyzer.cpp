// https://onlinejudge.org/external/118/11860.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define INF 1000000000

int main()
{
    int tc;
    string line, s;

    cin >> tc;
    cin.ignore();

    REPN(test_case, tc)
    {
        unordered_map<string, int> m;
        vector<string> words;
        while (getline(cin, line), line != "END")
        {
            for (auto &c : line)
                if (!isalpha(c))
                    c = ' ';
            istringstream iss(line);
            while (iss >> s)
            {
                words.push_back(s);
                m[s] = 0;
            }
        }
        int seen = 0, num_words = m.size(), n = words.size(), k = 0;
        pair<int, int> ans = {INF, INF};
        REP(i, n)
        {
            while (k < n and seen < num_words)
            {
                if (m[words[k]] == 0)
                    seen++;
                m[words[k]]++;
                k++;
            }
            if (seen == num_words)
                ans = min(ans, {k - i, i});
            m[words[i]]--;
            if (m[words[i]] == 0)
                seen--;
        }
        cout << "Document " << test_case << ": ";
        cout << ans.second + 1 << ' ' << ans.second + ans.first << '\n';
    }

    return 0;
}