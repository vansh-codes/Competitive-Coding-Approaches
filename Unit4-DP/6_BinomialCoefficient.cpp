//? https://www.geeksforgeeks.org/problems/ncr1019/1

#include <bits/stdc++.h>
using namespace std;

//Testcases: 3,2 -> 3; 2,4 -> 0; 5,0 -> 1
int nCr(int n, int r)
{
    if (r > n)
        return 0;
    int C[n + 1][r + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % 1000000007;
        }
    }
    return C[n][r] % 1000000007;
}

int main()
{
    int n, r;
    cin >> n >> r;

    cout << nCr(n, r) << "\n";

    return 0;
}