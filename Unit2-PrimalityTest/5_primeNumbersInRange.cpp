#include <bits/stdc++.h>
using namespace std;

vector<int> sieveOfAtkin(int limit) {
    vector<bool> is_prime(limit + 1, false);
    vector<int> primes;

    if (limit > 2) primes.push_back(2);
    if (limit > 3) primes.push_back(3);

    for (int x = 1; x * x <= limit; x++) {
        for (int y = 1; y * y <= limit; y++) {
            int n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) {
                is_prime[n] = !is_prime[n];
            }
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7) {
                is_prime[n] = !is_prime[n];
            }
            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11) {
                is_prime[n] = !is_prime[n];
            }
        }
    }

    for (int r = 5; r * r <= limit; r++) {
        if (is_prime[r]) {
            for (int i = r * r; i <= limit; i += r * r) {
                is_prime[i] = false;
            }
        }
    }

    for (int a = 5; a <= limit; a++) {
        if (is_prime[a]) {
            primes.push_back(a);
        }
    }

    return primes;
}

int main() {
    int limit;
    cout << "Enter the limit: ";
    cin >> limit;

    vector<int> primes = sieveOfAtkin(limit);

    cout << "Primes up to " << limit << " are: ";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}