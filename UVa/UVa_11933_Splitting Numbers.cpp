// https://onlinejudge.org/external/119/11933.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int n;

    while (scanf("%u", &n), n)
    {
        unsigned int a = 0, b = 0;
        unsigned int toAdd = 1;
        bool addToA = true;

        while (n)
        {
            if (n & 1)
            {
                if (addToA)
                    a += toAdd;
                else
                    b += toAdd;
                addToA = !addToA;
            }
            toAdd <<= 1;
            n >>= 1;
        }

        printf("%u %u\n", a, b);
    }
    return 0;
}