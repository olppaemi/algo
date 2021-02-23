// https://onlinejudge.org/external/4/417.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
typedef vector<int> vi;
typedef pair<int, int> ii;

map<string, int> word_index;
int idx = 1;

void enumerate(string word, size_t length)
{
    if (word.length() == length)
    {
        word_index[word] = idx++;
        return;
    }
    char startLetter;
    if (word.empty())
        startLetter = 'a';
    else
        startLetter = word[word.length() - 1] + 1;

    for (char c = startLetter; c <= 'z'; c++)
        enumerate(word + c, length);
}

int main()
{
    REPN(length, 5)
    {
        enumerate("", length);
    }

    string word;

    while (cin >> word)
    {
        cout << word_index[word] << '\n';
    }

    return 0;
}