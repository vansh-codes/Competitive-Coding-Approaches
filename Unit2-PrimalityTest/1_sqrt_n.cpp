#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> prime;

    for (int i = 2; i <= n; i++)
    {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            prime.push_back(i);
        }
    }

    for (int i = 0; i < prime.size(); i++)
    {
        cout << prime[i] << " ";
    }

    return 0;
}
