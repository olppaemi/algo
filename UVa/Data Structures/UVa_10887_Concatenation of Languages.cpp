// https://onlinejudge.org/external/108/10887.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

int main()
{
    int tc, m, n;
    char word[16];

    scanf("%d", &tc);
    REPN(test_case, tc)
    {
        unordered_set<string> a, b, ans;
        scanf("%d %d", &m, &n);
        gets(word);

        REP(i, m)
        {
            gets(word);
            a.insert(string(word));
        }
        REP(i, n)
        {
            gets(word);
            b.insert(string(word));
        }

        for (auto &x : a)
        {
            for (auto &y : b)
            {
                ans.insert(x + y);
            }
        }

        printf("Case %d: %u\n", test_case, ans.size());
    }
    return 0;
}