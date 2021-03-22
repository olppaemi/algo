#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPN(i, n) for (int i = 1; i <= n; ++i)

int card_value(string card)
{
    char v = card[0];
    if (v >= '2' and v <= '9')
        return v - '0';
    else
        return 10;
}

int main()
{
    int tc;
    vector<string> cards;

    cin >> tc;
    REPN(case_num, tc)
    {
        int y = 0;
        cards.assign(52, "");
        REP(i, 52)
        {
            cin >> cards[i];
        }
        reverse(cards.begin(), cards.end());
        REP(i, 3)
        {
            int x = card_value(cards[25]);
            y += x;
            cards.erase(cards.begin() + 25, cards.begin() + 26 + (10 - x));
        }
        reverse(cards.begin(), cards.end());
        cout << "Case " << case_num << ": " << cards[y - 1] << '\n';
    }

    return 0;
}