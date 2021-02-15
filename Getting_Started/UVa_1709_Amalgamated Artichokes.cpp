// https://onlinejudge.org/external/17/1709.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPN(i, n) for (int i = 1; i <= n; i++)
#define INF 1000000000
typedef vector<int> vi;
typedef tuple<int, int> ii;

double price(int p, int a, int b, int c, int d, int k)
{
    return p * (sin(a * k + b) + cos(c * k + d) + 2.0);
}

double find_minimum_cross_sum(vector<double> &a, int low, int mid, int high)
{
    double left_sum = INF, right_sum = INF;
    double sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += a[i];
        if (sum < left_sum)
            left_sum = sum;
    }
    sum = 0;
    for (int j = mid + 1; j <= high; j++)
    {
        sum += a[j];
        if (sum < right_sum)
            right_sum = sum;
    }
    return left_sum + right_sum;
}

double find_minimum_subarray(vector<double> &a, int low, int high)
{
    if (low == high)
        return a[low];
    int mid = (low + high) / 2;
    double left_sum = find_minimum_subarray(a, low, mid);
    double right_sum = find_minimum_subarray(a, mid + 1, high);
    double cross_sum = find_minimum_cross_sum(a, low, mid, high);
    if (left_sum <= right_sum and left_sum <= cross_sum)
        return left_sum;
    else if (right_sum <= left_sum and right_sum <= cross_sum)
        return right_sum;
    else
        return cross_sum;
}

double solution(int n, vector<double> &a)
{
    vector<double> change(n - 1);
    REP(i, n - 1)
    {
        change[i] = a[i + 1] - a[i];
    }
    return find_minimum_subarray(change, 0, change.size() - 1);
}

int main()
{
    int p, a, b, c, d, n;
    while (scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) == 6)
    {
        if (n == 1)
        {
            printf("%f\n", 0.0);
            continue;
        }
        vector<double> arr(n);
        REP(k, n)
        {
            arr[k] = price(p, a, b, c, d, k + 1);
        }
        double answer = solution(n, arr);
        if (answer < 0)
        {
            printf("%f\n", -answer);
        }
        else
        {
            printf("%f\n", 0.0);
        }
    }
    return 0;
}