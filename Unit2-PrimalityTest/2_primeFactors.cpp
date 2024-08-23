// ? Prime factor pairs
// example: n=4 => pair (2,2) is a factor pair made of both prime nums
// Note: (1,4) and (4,1) cannot be taken as they are not prime pairs

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<pair<int, int>> primePairs;

    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            for (int j = i; j <= n; j++) {
                if (isPrime(j) && i * j == n) {
                    primePairs.push_back({i, j});
                }
            }
        }
    }

    if (primePairs.size()) {
        for (auto pair : primePairs) {
            cout << pair.first << "," << pair.second << "\n";
        }
    } else {
        cout << "Not found any pairs";
    }

    return 0;
}
