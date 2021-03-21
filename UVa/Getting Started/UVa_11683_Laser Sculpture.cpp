#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; ++i)

int main()
{
    int height, length;
    int final_height[10000];

    while (scanf("%d %d", &height, &length), height)
    {
        int count = 0;
        scanf("%d", &final_height[0]);
        count += height - final_height[0];

        FOR(i, 1, length)
        {
            scanf("%d", &final_height[i]);
            if (final_height[i - 1] > final_height[i])
            {
                count += final_height[i - 1] - final_height[i];
            }
        }
        printf("%d\n", count);
    }
    return 0;
}