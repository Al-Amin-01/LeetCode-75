#include <bits/stdc++.h>
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        double sum = 0.0;
        double ans = 0.0;
        int n = nums.size();
        for (int i = 0; i < k; i++)
            sum += nums[i];
        ans = sum / k;
        for (int i = k; i < n; i++)
        {

            sum = sum + nums[i] - nums[i - k];

            ans = max(ans, sum / k);
        }

        return ans;
    }
};