#include <bits/stdc++.h>
using namespace std;

void traverse(vector<vector<int>> arr, int i, int j)
{
    if (i == arr.size() - 1 && j == arr[0].size() - 1)
    {
        cout << arr[i][j] << " ";
        return;
    }

    cout << arr[i][j] << " ";
    if (j < (arr[0].size() - 1))
        traverse(arr, i, j + 1);
    else if (i < (arr.size() - 1))
        traverse(arr, i + 1, 0);
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int i = 0, j = 0;
    traverse(arr, i, j);

    return 0;
}