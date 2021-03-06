// https://onlinejudge.org/external/2/216.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)

typedef pair<int, int> ii;

int n;
ii computers[8];
double dist[8][8];

double distance(ii a, ii b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)) + 16.0;
}

int main()
{
    int tc = 1;
    while (scanf("%d", &n), n)
    {
        REP(i, n)
        {
            scanf("%d %d", &computers[i].first, &computers[i].second);
        }

        REP(i, n)
        {
            REP(j, i)
            {
                double d = distance(computers[i], computers[j]);
                dist[i][j] = d;
                dist[j][i] = d;
            }
        }
        vector<int> network;
        vector<int> computer_idx;
        double min_cable = numeric_limits<double>::max();

        REP(i, n)
        {
            computer_idx.push_back(i);
        }

        do
        {
            double cable = 0;
            REP(i, n - 1)
            {
                cable += dist[computer_idx[i]][computer_idx[i + 1]];
            }

            if (cable < min_cable)
            {
                min_cable = cable;
                network = computer_idx;
            }

        } while (next_permutation(computer_idx.begin(), computer_idx.end()));

        printf("**********************************************************\n");
        printf("Network #%d\n", tc++);
        REP(i, n - 1)
        {
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",
                   computers[network[i]].first, computers[network[i]].second,
                   computers[network[i + 1]].first, computers[network[i + 1]].second,
                   dist[network[i]][network[i + 1]]);
        }
        printf("Number of feet of cable required is %.2f.\n", min_cable);
    }

    return 0;
}