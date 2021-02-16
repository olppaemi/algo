// https://onlinejudge.org/external/131/13181.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

int main()
{
    char bed[500001];
    while (scanf("%s", bed) == 1)
    {
        int answer = 0, prev = -1, n = strlen(bed);
        REP(i, n)
        {
            if (bed[i] == 'X')
            {
                if (prev == -1)
                {
                    answer = max(answer, (i - 0) - 1);
                    prev = i;
                }
                else
                {
                    answer = max(answer, (i - prev - 2) / 2);
                    prev = i;
                }
            }
        }
        if (prev != n - 1)
            answer = max(answer, ((n - 1) - prev) - 1);
        printf("%d\n", answer);
    }
    return 0;
}