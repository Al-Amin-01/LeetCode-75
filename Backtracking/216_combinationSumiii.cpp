#include <bits/stdc++.h>
class Solution
{
public:
    void call(int k, int n, vector<int> &v, vector<vector<int>> &ans)
    {
        if (v.size() == k)
        {
            if (accumulate(v.begin(), v.end(), 0) == n)
                ans.push_back(v);
            return;
        }
        for (int i = 1; i <= 9; i++)
        {
            if (v.empty() || i > v[v.size() - 1])
            {
                v.push_back(i);
                call(k, n, v, ans);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> v;
        call(k, n, v, ans);
        return ans;
    }
};