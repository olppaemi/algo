#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    int x, r, c;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf(" %c %d %d", &x, &r, &c);
        assert(r >= 4 and c >= 4);

        int ans;
        if (x == 'r' or x == 'Q')
            ans = min(r, c);
        else if (x == 'k')
            ans = (r * c + 1) / 2;
        else if (x == 'K')
            ans = ((r + 1) / 2) * ((c + 1) / 2);

        printf("%d\n", ans);
    }

    return 0;
}