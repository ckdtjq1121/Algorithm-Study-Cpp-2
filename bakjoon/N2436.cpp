
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (a < b)
        swap(a, b);

    int tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int g, l;
    cin >> g >> l;

    int ab = l / g;

    int ans = INT_MAX;
    int a, b;
    for (int i = 1; i <= sqrt(ab); i++)
    {
        if (ab % i == 0)
        {
            if (ans > (i * g) + (ab / i * g) && gcd(i, ab / i) == 1)
            {
                a = i * g;
                b = ab / i * g;

                ans = (i * g) + (ab / i * g);
            }
        }
    }

    cout << a << " " << b << "\n";
}