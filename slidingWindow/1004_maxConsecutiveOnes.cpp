#include <bits/stdc++.h>

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, cnt = 0, ans = 0;
        vector<int> zero;

        for (int j = 0; j < n; j++)
        {
            if (nums[j] == 0)
                zero.push_back(j);
        }
        zero.push_back(n);
        int m = zero.size();
        if (m <= k)
            return n;
        else
            ans = zero[k];

        for (int x = 1; x + k < m; x++)
        {
            ans = max(ans, zero[x + k] - zero[x - 1] - 1);
        }

        return ans;
    }
};