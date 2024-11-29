// https://www.geeksforgeeks.org/problems/print-pattern3549/1

// psuedo code
class Solution
{
private:
    vector<int> getPattern(int n, int current, vector<int> &ans)
    {
        if (current <= 0 || current > n)
        {
            ans.push_back(current);
            return ans;
        }
        ans.push_back(current);
        getPattern(n, current - 5, ans);
        ans.push_back(current);
        return ans;
    }

public:
    vector<int> pattern(int N)
    {
        // code here
        vector<int> ans;
        getPattern(N, N, ans);
        return ans;
    }
};