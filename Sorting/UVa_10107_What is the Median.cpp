// https://onlinejudge.org/external/101/10107.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr;
    int x;

    while (scanf("%d", &x) == 1)
    {
        arr.push_back(x);
        nth_element(arr.begin(), arr.begin() + arr.size() / 2, arr.end());
        int m1 = *(arr.begin() + arr.size() / 2);
        int m2 = m1;

        if (arr.size() % 2 == 0)
        {
            nth_element(arr.begin(), arr.begin() + arr.size() / 2 - 1, arr.end());
            m2 = *(arr.begin() + arr.size() / 2 - 1);
        }
        printf("%d\n", (m1 + m2) / 2);
    }

    return 0;
}