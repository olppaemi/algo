// https://onlinejudge.org/external/112/11286.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
typedef vector<int> vi;
typedef pair<int, int> ii;

// fast IO
static auto __ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

int main()
{
    int n, course;
    while (cin >> n, n)
    {
        unordered_map<string, int> frosh;
        int mx = 0;

        REP(i, n)
        {
            string str;
            vector<string> vs;
            REP(j, 5)
            {
                cin >> str;
                vs.emplace_back(str);
            }
            sort(begin(vs), end(vs));
            str.clear();
            for (auto &s : vs)
                str += s;
            frosh[str]++;
        }

        ii answer;
        for (auto &[k, v] : frosh)
        {
            if (v > answer.first)
                answer = {v, v};
            else if (v == answer.first)
                answer.second += v;
        }

        cout << answer.second << '\n';
    }
    return 0;
}