// https://onlinejudge.org/external/100/10020.pdf

#include <bits/stdc++.h>
using namespace std;

struct coverage
{
    int left, right;

    bool operator<(const coverage &b)
    {
        if (this->left < b.left)
            return true;
        else if (this->left == b.left)
            return this->right > b.right;
        return false;
    }
};

int main()
{
    int tc, m;
    int l, r;

    scanf("%d", &tc);
    while (tc--)
    {
        vector<coverage> v;
        vector<int> answer;

        scanf("%d", &m);
        while (scanf("%d %d", &l, &r), l || r)
        {
            if (l < 0 and r < 0)
                continue;
            v.push_back({l, r});
        }

        sort(v.begin(), v.end());
        int i = 0, covered = 0, next_covered = 0;
        int n = v.size();

        while (i < n)
        {
            int pos = -1;
            while (i < n and v[i].left <= covered)
            {
                if (v[i].right > next_covered)
                {
                    next_covered = v[i].right;
                    pos = i;
                }
                ++i;
            }
            if (pos < 0)
                break;

            answer.push_back(pos);
            covered = next_covered;
            if (covered >= m)
                break;
            i = pos + 1;
        }
        if (covered < m)
            printf("0\n");
        else
        {
            printf("%d\n", answer.size());
            for (auto idx : answer)
                printf("%d %d\n", v[idx].left, v[idx].right);
        }
        puts("");
    }

    return 0;
}