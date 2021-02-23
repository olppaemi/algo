// https://onlinejudge.org/external/9/978.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

void solution(int f, int sg, int sb, multiset<int> &green, multiset<int> &blue)
{
    auto gsoldier = green.begin(), bsoldier = blue.begin();
    int x;

    while (green.size() > 0 and blue.size() > 0)
    {
        int gsurvied[f], gidx = 0;
        int bsurvied[f], bidx = 0;

        REP(i, f)
        {
            if (green.size() == 0 || blue.size() == 0)
                break;
            gsoldier = --green.end();
            bsoldier = --blue.end();

            if (*gsoldier > *bsoldier)
            {
                x = *gsoldier - *bsoldier;
                green.erase(gsoldier);
                blue.erase(bsoldier);
                gsurvied[gidx++] = x;
            }
            else if (*gsoldier < *bsoldier)
            {
                x = *bsoldier - *gsoldier;
                green.erase(gsoldier);
                blue.erase(bsoldier);
                bsurvied[bidx++] = x;
            }
            else
            {
                green.erase(gsoldier);
                blue.erase(bsoldier);
            }
        }
        REP(i, gidx)
        {
            green.insert(gsurvied[i]);
        }
        REP(i, bidx)
        {
            blue.insert(bsurvied[i]);
        }
    }

    if (green.empty() and blue.empty())
        printf("green and blue died\n");
    else if (green.size() > 0)
    {
        printf("green wins\n");
        for (auto it = green.rbegin(); it != green.rend(); it++)
            printf("%d\n", *it);
    }
    else
    {
        printf("blue wins\n");
        for (auto it = blue.rbegin(); it != blue.rend(); it++)
            printf("%d\n", *it);
    }
}

int main()
{
    int n, f, sg, sb;
    int x;

    scanf("%d", &n);
    while (n--)
    {
        multiset<int> green, blue;

        scanf("%d %d %d", &f, &sg, &sb);
        REP(i, sg)
        {
            scanf("%d", &x);
            green.insert(x);
        }
        REP(i, sb)
        {
            scanf("%d", &x);
            blue.insert(x);
        }

        solution(f, sg, sb, green, blue);
        if (n)
            puts("");
    }

    return 0;
}