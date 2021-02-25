// https://onlinejudge.org/external/113/11308.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

#define ALL(v) v.begin(), v.end()
#define SORT(v) sort(ALL(v))

int main()
{
    int t, m, n, b, k;
    string title, ingredient, recipe;
    int price, unit;

    cin >> t;
    while (t--)
    {
        cin.ignore();
        getline(cin, title);
        cin >> m >> n >> b;
        map<string, int> prices;
        REP(i, m)
        {
            cin >> ingredient >> price;
            prices.insert({ingredient, price});
        }

        map<string, int> requirements;
        vector<pair<int, string>> ans;
        REP(i, n)
        {
            cin.ignore();
            getline(cin, recipe);
            requirements[recipe] = 0;

            cin >> k;
            REP(j, k)
            {
                cin >> ingredient >> unit;
                requirements[recipe] += prices[ingredient] * unit;
            }
            ans.push_back({requirements[recipe], recipe});
        }
        SORT(ans);

        for (auto &c : title)
            c = toupper(c);

        cout << title << '\n';
        bool can_make = false;
        for (const auto &x : ans)
        {
            if (x.first <= b)
            {
                cout << x.second << '\n';
                can_make = true;
            }
        }
        if (!can_make)
            cout << "Too expensive!\n";
        cout << '\n';
    }

    return 0;
}