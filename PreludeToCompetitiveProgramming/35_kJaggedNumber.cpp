//?https://www.geeksforgeeks.org/k-rough-number-k-jagged-number/
// k-rough/k-jagged or not.
#include <bits/stdc++.h>
using namespace std;

// Returns true if n is k rough else false
bool isKRough(int n, int k)
{
    // If n is even, then smallest prime
    // factor becomes 2.
    if (n % 2 == 0)
        return (k <= 2);

    // n must be odd at this point. So we
    // can skip one element (Note i = i +2)
    for (int i = 3; i * i <= n; i = i + 2)
        if (n % i == 0)
            return (i >= k);

    return (n >= k);
}

/* Driver program to test above function */
int main()
{
    int n = 75, k = 3;
    if (isKRough(n, k))
        cout << n << " is a "
             << k << "-rough number\n";
    else
        cout << n << " is not a "
             << k << "-rough number\n";
    return 0;
}
