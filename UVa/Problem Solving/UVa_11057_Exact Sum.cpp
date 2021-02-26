// https://onlinejudge.org/external/110/11057.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

pair<int, int> solution(int x, int n, int a[])
{
    pair<int, int> ans = {0, 0};
    sort(a, a + n);
    int left = 0, right = n - 1;

    while (left < right)
    {
        if (a[left] + a[right] < x)
            left++;
        else if (a[left] + a[right] == x)
        {
            ans.first = a[left];
            ans.second = a[right];
            left++;
            right--;
        }
        else
            right--;
    }

    return ans;
}

int main()
{
    int n, m;
    int a[10000];

    while (scanf("%d", &n) != EOF)
    {
        REP(i, n)
        {
            scanf("%d", &a[i]);
        }
        scanf("%d", &m);
        auto [x, y] = solution(m, n, a);
        printf("Peter should buy books whose prices are %d and %d.\n\n", x, y);
    }
    return 0;
}