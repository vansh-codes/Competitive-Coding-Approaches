//? https://www.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> stockBuySell(vector<int> A, int n)
{
    vector<vector<int>> result;

    if (n <= 1)
    {
        return result;
    }

    int buy = 0;
    int sell = -1; // -1 indicates no valid sell index yet

    for (int i = 1; i < n; ++i)
    {
        if (A[i] > A[i - 1])
        {
            sell = i;
        }
        else
        {
            if (sell != -1)
            {
                result.push_back({buy, sell});
            }
            buy = i;
            sell = -1;
        }
    }

    // If there's a valid segment ending at the last day
    if (sell != -1)
    {
        result.push_back({buy, sell});
    }

    return result;
}


// Can be incorrect :(
int main()
{
    int n;
    cin>>n;

    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    vector<vector<int>> result = stockBuySell(A, n);
    int profit = 0;
    for(int i=0;i<result.size();i++){
        profit += A[result[i][1]] - A[result[i][0]];
    }
    cout<<profit<<endl;

    return 0;
}