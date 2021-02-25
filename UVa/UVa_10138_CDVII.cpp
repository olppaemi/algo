// https://onlinejudge.org/external/101/10138.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define SORTV(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))

typedef vector<int> vi;
typedef pair<int, int> ii;

struct record
{
    long long bills;
    int time;
    int pos;
    bool entered;
};

int toll[24];

void solution(vector<tuple<string, string, string, int>> &v)
{
    map<string, record> record;

    for (auto &[date, plate, word, location] : v)
    {
        int hour = stoi(date.substr(6, 2));
        if (word == "enter")
        {
            record[plate].time = hour;
            record[plate].pos = location;
            record[plate].entered = true;
        }
        else if (word == "exit")
        {
            if (record[plate].entered == true)
            {
                record[plate].bills += abs(location - record[plate].pos) * toll[record[plate].time] + 100;
                record[plate].entered = false;
            }
        }
    }

    for (auto &[plate, value] : record)
    {
        if (value.bills > 0)
        {
            value.bills += 200;
            printf("%s $%lld.%02lld\n", plate.c_str(), value.bills / 100, value.bills % 100);
        }
    }
}

int main()
{
    int tc;
    string plate, word, date, line;
    int hour, location;

    cin >> tc;
    while (tc--)
    {
        vector<tuple<string, string, string, int>> v;
        REP(i, 24)
        {
            cin >> toll[i];
        }
        cin.ignore();
        while (getline(cin, line), line != "")
        {
            istringstream iss(line);
            iss >> plate >> date >> word >> location;
            v.push_back({date, plate, word, location});
            line = "";
        }

        SORTV(v);
        solution(v);
        if (tc)
            cout << '\n';
    }

    return 0;
}