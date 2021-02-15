// https://onlinejudge.org/external/123/12372.pdf

#include <bits/stdc++.h>

using namespace std;

string solution(int length, int width, int height)
{
    if (length <= 20 and width <= 20 and height <= 20)
        return "good";
    return "bad";
}

int main()
{
    int tc;
    scanf("%d", &tc);
    int length, width, height;

    for (int i = 1; i <= tc; i++)
    {
        scanf("%d %d %d", &length, &width, &height);
        printf("Case %d: %s\n", i, solution(length, width, height).c_str());
    }
    return 0;
}