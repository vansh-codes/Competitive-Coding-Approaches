#include <bits/stdc++.h>
using namespace std;

int maxSubArray(int nums[], int n)
{
    int maxi = nums[0];
    int sum = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (sum < 0)
            sum = 0;
        sum += nums[i];
        maxi = max(maxi, sum);
    }
    return maxi;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxSubArray(arr, n) << "\n";

    return 0;
}