// ? Given n, find nearest prime number to n whose sum = n
// example: n=74, pair would be 71 which is nearest and 3 => (71,3)

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

    int start = 0;
    int end = prime.size() - 1;
    bool foundPair = false;
    while (start <= end)
    {
        if (prime[start] + prime[end] == n)
        {
            foundPair = true;
            cout << "(" << prime[end] << "," << prime[start] << ")\n";
            start++;
            end--;
            // break;
        }
        else if (prime[start] + prime[end] > n)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    if (!foundPair)
    {
        cout << "No pairs found\n";
    }

    return 0;
}