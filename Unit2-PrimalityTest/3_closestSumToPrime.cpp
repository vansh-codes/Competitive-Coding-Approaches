// ? Given n, find nearest prime number to n whose sum = n
// example: n=74, pair would be 71 which is nearest and 3 => (71,3)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    // OPTIMIZED using Sieve of Eratosthenes
    vector<int> prime(n+1, 1);
    for(int i=2;i*i<=n;i++){
        if(prime[i]==1){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }

    vector<vector<int>> primePairs;
    for(int i=2;i<=n/2;i++){
        if(prime[i] && prime[n-i] && i<=n-i){
            primePairs.push_back({i, n-i});
        }
    }

    if(primePairs.size()){
        for(auto pair: primePairs){
            cout<<"("<<pair[0]<<","<<pair[1]<<")\n";
        }
    } else {
        cout<<"No pairs found\n";
    }



    // BRUTE FORCE
/*  vector<int> prime;
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
    } */

    return 0;
}