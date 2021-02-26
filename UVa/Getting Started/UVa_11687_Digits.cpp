// https://onlinejudge.org/external/116/11687.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define INF 1000000000
typedef vector<int> vi;
typedef tuple<int, int> ii;

int solution(int i, string number)
{
    string num_size(to_string(number.size()));

    if (num_size == number)
        return i;
    return solution(i + 1, num_size);
}

int main()
{
    string number;
    while (cin >> number, number != "END")
    {
        cout << solution(1, number) << '\n';
    }
    return 0;
}