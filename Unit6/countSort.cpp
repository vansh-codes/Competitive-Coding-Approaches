#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }


    int maxi = 0;
    for(int i=0; i<n; i++){
        maxi = max(maxi, arr[i]);
    }

    vector<int> count(maxi+1, 0);

    for (int i = 0; i < n; ++i)
    {
        count[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= maxi; ++i)
    {
        while (count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }

    cout << "Sorted array: ";
    for (const int &element : arr)
    {
        cout << element << " ";
    }

    return 0;
}