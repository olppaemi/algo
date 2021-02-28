// https://onlinejudge.org/external/11/1196.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

#define MX 10001
struct block
{
    int l, m;

    bool operator<(const block &b) const
    {
        return l < b.l || (l == b.l && m < b.m);
    }
} blocks[MX];
int n;
int seq[MX], sz;

int main()
{
    while (scanf("%d", &n), n)
    {
        REP(i, n)
        {
            scanf("%d %d", &blocks[i].l, &blocks[i].m);
        }
        sort(blocks, blocks + n);
        sz = 0;
        REP(i, n)
        {
            int pos = upper_bound(seq, seq + sz, blocks[i].m) - seq;
            if (pos == sz)
                ++sz;
            seq[pos] = blocks[i].m;
        }
        printf("%d\n", sz);
    }
    puts("*");

    return 0;
}