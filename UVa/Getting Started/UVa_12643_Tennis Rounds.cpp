#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, i, j;
    while (scanf("%d %d %d", &n, &i, &j) != EOF)
    {
        --i, --j;
        int round = 1;
        while (1)
        {
            i /= 2;
            j /= 2;
            if (i == j)
                break;
            ++round;
        }
        printf("%d\n", round);
    }

    return 0;
}