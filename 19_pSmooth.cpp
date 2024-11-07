#include <bits/stdc++.h>
using namespace std;

//? check if a given number is p-smooth or not
//* P-smooth is a +ve integer where all prime nums are <= to given prime p
// Testcase: 60 3, 100 5
int main()
{
    int n, p;
    cin >> n >> p;

    if (p > n)
    {
        cout << "Not P-smooth\n";
        return 0;
    }

    int maxi = INT_MIN;

    while (n % 2 == 0)
    {
        maxi = max(maxi, 2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            if (i > maxi)
                maxi = i;
            n /= i;
        }
    }
    if (n > 1)
    {
        maxi = n;
    }

    if (maxi <= p)
    {
        cout << "P-smooth\n";
    }
    else
    {
        cout << "Not P-smooth\n";
    }

    return 0;
}