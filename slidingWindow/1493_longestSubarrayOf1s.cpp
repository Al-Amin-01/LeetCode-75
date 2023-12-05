#include <bits/stdc++.h>
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size(), i = 0, j = 0;
        int cnt = 0, ans = INT_MIN;

        while (i < n)
        {
            if (nums[i] == 0)
            {
                cnt++;
            }
            while (cnt > 1)
            {
                if (nums[j] == 0)
                {
                    cnt--;
                }
                j++;
            }
            ans = max(ans, i - j);
            i++;
        }

        return ans;
    }
};