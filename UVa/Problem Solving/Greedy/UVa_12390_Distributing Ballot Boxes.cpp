#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    int N, B;

    while (scanf("%d %d", &N, &B), N != -1 and B != -1)
    {
        priority_queue<tuple<double, int, int>> pq;
        REP(i, N)
        {
            int a;
            scanf("%d", &a);
            pq.push({(double)a / 1.0, a, 1});
        }
        B -= N;
        while (B--)
        {
            auto [ratio, num, box] = pq.top();
            pq.pop();
            pq.push({num / (box + 1.0), num, box + 1});
        }
        printf("%d\n", (int)ceil(get<0>(pq.top())));
    }

    return 0;
}