// GFG Link: https://www.geeksforgeeks.org/problems/champagne-overflow2636/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double pourWater(double water, int r, int c)
    {
        if (r < 0 || c < 0 || c > r)
            return 0;
        if (r == 0 && c == 0)
            return min(water, 1.0);
        if (water > 1.0)
        {
            double extraWater = water - 1.0;
            return 1.0 + (pourWater(extraWater / 2.0, r - 1, c - 1) + pourWater(extraWater / 2.0, r, c - 1));
        }
        return min(1.0, water);
    }

    double waterOverflow(int K, int R, int C)
    {
        return pourWater((double)K, R, C);
    }
};

int main()
{
    int k, r, c;
    cin >> k >> r >> c;

    Solution obj;
    cout << fixed << setprecision(6) << obj.waterOverflow(k, r, c) << endl;

    return 0;
}