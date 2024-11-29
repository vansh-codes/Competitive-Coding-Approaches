// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the sorted string
string getSortedString(string str, int n)
{
    // Create two priority queues to store lowercase and
    // uppercase characters separately
    priority_queue<char, vector<char>, greater<char>>
        lower, upper;

    // Loop through the string and insert each character
    // into the appropriate queue
    for (int i = 0; i < n; i++)
    {
        if (islower(str[i]))
        {
            lower.push(str[i]);
        }
        else
        {
            upper.push(str[i]);
        }
    }

    // Loop through the string again and replace each
    // character with the next lowest or highest character
    // in the appropriate queue
    for (int i = 0; i < n; i++)
    {
        if (islower(str[i]))
        {
            str[i] = lower.top();
            lower.pop();
        }
        else
        {
            str[i] = upper.top();
            upper.pop();
        }
    }

    // Return the sorted string
    return str;
}

// Driver code
int main()
{
    string s;
    cin>>s;
    int n = s.size();

    cout << getSortedString(s, n);

    return 0;
}
// This code is contributed by Ravi Singh
