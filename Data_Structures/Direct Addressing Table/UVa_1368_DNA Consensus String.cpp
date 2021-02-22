// https://onlinejudge.org/external/13/1368.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define RESET(a) memset(a, 0, sizeof(a))

#define MAX_M 50
#define MAX_N 1001

void solution(int n, int length, char dna[][MAX_N])
{
    char answer[MAX_N] = {};
    const char gene[] = "ACGT";
    int error = 0;
    int cnt[4], mx;

    REP(j, length)
    {
        RESET(cnt);
        mx = 0;
        REP(i, n)
        {
            cnt[find(gene, gene + 4, dna[i][j]) - gene]++;
        }
        REP(i, 4)
        {
            if (cnt[i] > cnt[mx])
                mx = i;
        }
        answer[j] = gene[mx];
        error += n - cnt[mx];
    }

    printf("%s\n", answer);
    printf("%d\n", error);
}

int main()
{
    int tc, m, n;
    char dna[MAX_M][MAX_N];

    scanf("%d", &tc);
    while (tc--)
    {
        RESET(dna);
        scanf("%d %d", &m, &n);
        REP(i, m)
        {
            scanf("%s", dna[i]);
        }
        solution(m, n, dna);
    }
    return 0;
}