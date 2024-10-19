// psuedo code
// https://www.geeksforgeeks.org/problems/power-of-numbers-1587115620/1
long long power(int N, int R)
{
    if (R == 0)
    {
        return 1;
    }

    if (R == 1)
    {
        return N;
    }

    long long ans = power(N, R / 2);

    // even
    if (R % 2 == 0)
    {
        return (ans * ans) % 1000000007;    // N^R = (N^(R/2) * N^(R/2)) % 1000000007
    }

    // odd
    else
    {
        return ((N * ans) % 1000000007 * ans) % 1000000007;     // N^R = (N * N^(R/2) * N^(R/2)) % 1000000007
    }
}