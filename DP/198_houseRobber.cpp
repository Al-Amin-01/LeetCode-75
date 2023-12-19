#include <bits/stdc++.h>
class Solution
{
public:
    int call(int ind, vector<int> &nums, vector<int> &dp)
    {

        if (ind == 0)
            return dp[ind] = nums[0];
        if (ind == 1)
            return dp[ind] = max(nums[0], nums[1]);
        if (dp[ind] != -1)
            return dp[ind];
        int x = call(ind - 1, nums, dp);
        int y = call(ind - 2, nums, dp);
        dp[ind] = max(nums[ind] + y, x);
        return dp[ind];
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // if(n==0) return nums[0];
        vector<int> dp(n, -1);
        return call(n - 1, nums, dp);
    }
};