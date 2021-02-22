// https://onlinejudge.org/external/116/11629.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
typedef vector<int> vi;
typedef pair<int, int> ii;

bool solution(map<string, int> &record, string query)
{
    istringstream iss(query);
    string str;
    int sum = 0, num;
    while (iss >> str)
    {
        if (str == "+")
            continue;
        else if (str == "<")
        {
            iss >> num;
            if (sum < num * 10)
                return true;
            else
                return false;
        }
        else if (str == "<=")
        {
            iss >> num;
            if (sum <= num * 10)
                return true;
            else
                return false;
        }
        else if (str == ">")
        {
            iss >> num;
            if (sum > num * 10)
                return true;
            else
                return false;
        }
        else if (str == ">=")
        {
            iss >> num;
            if (sum >= num * 10)
                return true;
            else
                return false;
        }
        else if (str == "=")
        {
            iss >> num;
            if (sum == num * 10)
                return true;
            else
                return false;
        }
        else
            sum += record[str];
    }

    return false;
}

int main()
{
    int p, g;
    string party, query;
    double percentage;
    map<string, int> record;

    cin >> p >> g;
    REP(i, p)
    {
        cin >> party >> percentage;
        record[party] = percentage * 10;
    }
    cin.ignore();
    REPN(i, g)
    {
        getline(cin, query);
        bool correct = solution(record, query);
        cout << "Guess #" << i << " was " << (correct ? "correct.\n" : "incorrect.\n");
    }

    return 0;
}