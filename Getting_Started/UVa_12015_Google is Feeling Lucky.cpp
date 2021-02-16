// https://onlinejudge.org/external/120/12015.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INF 1000000000
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{
    freopen("input.txt", "r", stdin);
    int tc;
    vector<pair<int, string>> web_page(10);

    scanf("%d", &tc);
    REPN(test_case, tc)
    {
        int max = 0;
        REP(i, 10)
        {
            cin >> web_page[i].second >> web_page[i].first;
            if (web_page[i].first > max)
                max = web_page[i].first;
        }

        printf("Case #%d:\n", test_case);
        REP(i, 10)
        {
            if (web_page[i].first == max)
                cout << web_page[i].second << '\n';
        }
    }

    return 0;
}