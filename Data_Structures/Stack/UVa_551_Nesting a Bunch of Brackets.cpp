// https://onlinejudge.org/external/5/551.pdf

#include <bits/stdc++.h>
using namespace std;

bool is_lparen(char c)
{
    return c == '(' or c == '[' or c == '{' or c == '<';
}
bool is_rparen(char c)
{
    return c == ')' or c == ']' or c == '}' or c == '>';
}

pair<bool, int> solution(size_t n, char exp[])
{
    stack<char> s;
    int i = 0, pos = 0;
    for (; i < n; i++)
    {
        pos++;
        if (is_lparen(exp[i]))
        {
            if (i < n - 1 and exp[i] == '(' and exp[i + 1] == '*')
            {
                s.push('*');
                i++;
            }
            else
                s.push(exp[i]);
        }
        else if (is_rparen(exp[i]) or (i < n - 1 and exp[i] == '*' and exp[i + 1] == ')'))
        {
            if (s.empty())
                break;
            if (exp[i] == '*')
            {
                if (s.top() != '*')
                    break;
                s.pop();
                i++;
            }
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
            else if (exp[i] == '}')
            {
                if (s.top() != '{')
                    break;
                s.pop();
            }
            else if (exp[i] == '>')
            {
                if (s.top() != '<')
                    break;
                s.pop();
            }
        }
    }

    if (i < n || !s.empty())
    {
        if (i == n and !s.empty())
            pos++;
        return {false, pos};
    }
    else
        return {true, 0};
}

int main()
{
    char expression[3010];
    while (gets(expression))
    {
        bool proper;
        int pos;
        tie(proper, pos) = solution(strlen(expression), expression);
        if (proper)
            printf("YES\n");
        else
            printf("NO %d\n", pos);
    }

    return 0;
}