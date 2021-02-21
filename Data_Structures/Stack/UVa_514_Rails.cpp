// https://onlinejudge.org/external/5/514.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

void marshal(int n)
{
    int t;
    while (1)
    {
        stack<int> train;
        int j = 0;
        REP(i, n)
        {
            scanf("%d", &t);
            if (t == 0)
                return;

            while (j < n and j != t)
            {
                if (train.size() > 0 and train.top() == t)
                    break;
                j++;
                train.push(j);
            }
            if (train.top() == t)
                train.pop();
        }
        if (train.size() == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
}

int main()
{
    int n;
    while (scanf("%d", &n), n)
    {
        marshal(n);
        puts("");
    }

    return 0;
}