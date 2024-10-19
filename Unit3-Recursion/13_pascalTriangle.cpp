#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/pascals-triangle/

void pascalTriangle(int n, vector<vector<int>> &pascal, int row)
{
    if (row > n)
    {
        return;
    }
    vector<int> temp(row, 1);
    if (row == 1 || row == 2)
    {
        pascal.push_back(temp);
    }
    else
    {
        for (int i = 1; i < row - 1; i++)
        {
            temp[i] = pascal[pascal.size() - 1][i - 1] + pascal[pascal.size() - 1][i];
        }
        pascal.push_back(temp);
    }
    pascalTriangle(n, pascal, row+1);
}

int main()
{
    int n; // no. of rows
    cin >> n;

    if(n<=0) cout<< -1;

    vector<vector<int>> pascal(n);
    pascalTriangle(n, pascal, 1);
    for (int i = 0; i < pascal.size(); i++)
    {
        for (int j = 0; j < pascal[i].size(); j++)
        {
            cout << pascal[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}