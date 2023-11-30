#include <bits/stdc++.h>

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> post(n);
        pre[0] = INT_MAX;
        post[n - 1] = INT_MIN;
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            pre[i] = min(pre[i - 1], nums[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            post[i] = max(post[i + 1], nums[i + 1]);
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i] > pre[i] && nums[i] < post[i])
                return true;
        }

        return false;
    }
};