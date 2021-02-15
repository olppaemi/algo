// https://onlinejudge.org/external/104/10424.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define INF 1000000000
typedef vector<int> vi;
typedef tuple<int, int> ii;

int digit_sum(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int love(char *s)
{
    int answer = 0;
    REP(i, strlen(s))
    {
        if (isalpha(s[i]))
            answer += tolower(s[i]) - 'a' + 1;
    }
    while (answer >= 10)
        answer = digit_sum(answer);
    return answer;
}

#define MAX_LEN 30
int main()
{
    char s1[MAX_LEN], s2[MAX_LEN];

    while (cin.getline(s1, MAX_LEN))
    {
        cin.getline(s2, MAX_LEN);
        int x = love(s1), y = love(s2);
        if (x > y)
            swap(x, y);
        printf("%.2f %%\n", x / (double)y * 100.0);
    }

    return 0;
}