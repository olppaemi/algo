// https://onlinejudge.org/external/121/12190.pdf

#include <bits/stdc++.h>
using namespace std;

int consumtion(int price)
{
    int cons = 0;
    cons += min(max(0, price / 2), 100);
    price -= 2 * 100;

    cons += min(max(0, price / 3), 9900);
    price -= 3 * 9900;

    cons += min(max(0, price / 5), 990000);
    price -= 5 * 990000;

    cons += max(0, price / 7);
    return cons;
}

int pay(int cons)
{
    int price = 0;
    price += min(max(0, cons * 2), 2 * 100);
    cons -= 100;

    price += min(max(0, cons * 3), 3 * 9900);
    cons -= 9900;

    price += min(max(0, cons * 5), 5 * 990000);
    cons -= 990000;

    price += max(0, cons * 7);
    return price;
}

int main()
{
    int a, b;
    while (scanf("%d %d", &a, &b), a || b)
    {
        int total = consumtion(a);
        int begin = 0, end = total;
        int answer = 0;
        while (begin < end)
        {
            int mid = (begin + end) / 2;
            int diff = pay(total - mid) - pay(mid);
            if (diff > b)
                begin = mid;
            else if (diff < b)
                end = mid;
            else
            {
                answer = mid;
                break;
            }
        }
        printf("%d\n", pay(answer));
    }

    return 0;
}