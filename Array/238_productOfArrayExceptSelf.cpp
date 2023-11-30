#include <bits/stdc++.h>
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        int cntZero = 0, x = -1;
        long long pro = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                cntZero++, x = i;
            else
                pro *= nums[i];
        }
        vector<int> ans(n, 0);
        if (cntZero > 1)
            return ans;
        if (cntZero == 1)
        {
            ans[x] = pro;
        }
        else
            for (int i = 0; i < n; i++)
            {
                ans[i] = pro / nums[i];
            }
        return ans;
    }
};