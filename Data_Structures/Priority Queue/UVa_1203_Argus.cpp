// https://onlinejudge.org/external/12/1203.pdf

#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> iii;

int main()
{
    char op[10];
    int q_num, period, k;
    priority_queue<iii> pq;

    while (scanf("%s", op), strcmp(op, "#"))
    {
        scanf("%d %d", &q_num, &period);
        pq.push({-period, -q_num, period});
    }
    scanf("%d", &k);
    while (k--)
    {
        int time, num, p;
        tie(time, num, p) = pq.top();
        printf("%d\n", -num);
        pq.pop();
        pq.push({time - p, num, p});
    }

    return 0;
}