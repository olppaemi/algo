// https://onlinejudge.org/external/130/13037.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)

int only_possessed(unordered_set<int> &a, unordered_set<int> &b, unordered_set<int> &c)
{
    int result = 0;
    for (int x : a)
    {
        if (!b.count(x) and !c.count(x))
            result++;
    }
    return result;
}

int missing(unordered_set<int> &a, unordered_set<int> &b, unordered_set<int> &c)
{
    int result = 0;
    for (int x : b)
    {
        if (!a.count(x) and c.count(x))
            result++;
    }
    return result;
}

int main()
{
    int tc, L, R, S, x;
    unordered_set<int> a, b, c;

    scanf("%d", &tc);

    REPN(test_case, tc)
    {
        a.clear();
        b.clear();
        c.clear();
        scanf("%d %d %d", &L, &R, &S);
        a.reserve(2 * L);
        b.reserve(2 * R);
        c.reserve(2 * S);

        REP(i, L)
        {
            scanf("%d", &x);
            a.insert(x);
        }
        REP(i, R)
        {
            scanf("%d", &x);
            b.insert(x);
        }
        REP(i, S)
        {
            scanf("%d", &x);
            c.insert(x);
        }

        printf("Case #%d:\n", test_case);
        printf("%d %d\n", only_possessed(a, b, c), missing(a, b, c));
        printf("%d %d\n", only_possessed(b, a, c), missing(b, a, c));
        printf("%d %d\n", only_possessed(c, a, b), missing(c, a, b));
    }
    return 0;
}