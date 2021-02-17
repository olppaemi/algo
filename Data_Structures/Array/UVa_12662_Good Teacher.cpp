// https://onlinejudge.org/external/126/12662.pdf

#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

void solution(int s, int q, string student[], int query[])
{
    int qr, left, right, distance;
    REP(i, q)
    {
        qr = query[i] - 1;
        if (student[qr] != "?")
        {
            cout << student[qr] << '\n';
        }
        else
        {
            left = -1, right = -1;
            for (int j = qr - 1; j >= 0; j--)
            {
                if (student[j] != "?")
                {
                    left = j;
                    break;
                }
            }

            for (int j = qr + 1; j < s; j++)
            {
                if (student[j] != "?")
                {
                    right = j;
                    break;
                }
            }
            if (left == -1)
            {
                distance = right - qr;
                REP(i, distance)
                {
                    cout << "left of ";
                }
                cout << student[right] << '\n';
            }
            else if (right == -1)
            {
                distance = qr - left;
                REP(i, distance)
                {
                    cout << "right of ";
                }
                cout << student[left] << '\n';
            }
            else if (qr - left == right - qr)
            {
                cout << "middle of " << student[left] << " and " << student[right] << '\n';
            }
            else if (qr - left < right - qr)
            {
                distance = qr - left;
                REP(i, distance)
                {
                    cout << "right of ";
                }
                cout << student[left] << '\n';
            }
            else
            {
                distance = right - qr;
                REP(i, distance)
                {
                    cout << "left of ";
                }
                cout << student[right] << '\n';
            }
        }
    }
}

int main()
{
    string student[100];
    int query[100];
    int s, q;
    cin >> s;
    REP(i, s)
    {
        cin >> student[i];
    }
    cin >> q;
    REP(i, q)
    {
        cin >> query[i];
    }
    solution(s, q, student, query);

    return 0;
}