// https://onlinejudge.org/external/116/11687.pdf

#include <bits/stdc++.h>
using namespace std;

int solution(int i, string number)
{
    string num_digits(to_string(number.size()));

    if (num_digits == number)
        return i;
    return solution(i + 1, num_digits);
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