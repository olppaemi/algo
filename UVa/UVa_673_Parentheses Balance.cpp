// https://onlinejudge.org/external/6/673.pdf

#include <bits/stdc++.h>
using namespace std;

bool is_lparen(char c)
{
    return c == '(' or c == '[';
}
bool is_rparen(char c)
{
    return c == ')' or c == ']';
}

const char *solution(size_t n, char exp[])
{
    stack<char> s;
    int i = 0;
    for (; i < n; i++)
    {
        if (is_lparen(exp[i]))
        {
            s.push(exp[i]);
        }
        else if (is_rparen(exp[i]))
        {
            if (s.empty())
                break;

            else if (exp[i] == ')')
            {
                if (s.top() != '(')
                    break;
                s.pop();
            }
            else if (exp[i] == ']')
            {
                if (s.top() != '[')
                    break;
                s.pop();
            }
        }
    }

    if (i < n || !s.empty())
        return "No";

    else
        return "Yes";
}

int main()
{
    int tc;
    char str[130];

    scanf("%d ", &tc);
    while (tc--)
    {
        gets(str);
        printf("%s\n", solution(strlen(str), str));
    }

    return 0;
}