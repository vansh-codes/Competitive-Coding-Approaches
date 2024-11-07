#include <bits/stdc++.h>
using namespace std;

bool isRotation(string A, string B)
{
    return A.size() == B.size() && (A + A).find(B) != string::npos;
    // return A.size() == B.size() && (B + B).find(A) != string::npos;  // works for this as well
}

bool isRotation1(string A, string B)
{
    if (A.size() != B.size())
        return false;
    for (int i = 0; i < A.size(); i++)
    {
        bool isRotationPossible = true;
        for (int j = 0; j < A.size(); j++)
        {
            if (B[i] != A[j])
            {
                isRotationPossible = false;
                break;
            }
        }
        if (isRotationPossible)
            return true;
    }
    return false;
}

int main()
{
    string a, b;
    cin >> a >> b;

    cout << isRotation(a, b) << "\n";
    cout << isRotation1(a, b) << "\n";

    return 0;
}