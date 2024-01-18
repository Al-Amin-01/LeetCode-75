#include <bits/stdc++.h>
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;

        while (i < n)
        {
            if (n == 1 || nums[i] >= n - i - 1)
                return true;
            if (nums[i] == 0)
                return false;

            int in = 0, val = 0;
            for (int j = 1; j <= nums[i]; j++)
            {
                if (nums[i + j] + j > val)
                {
                    val = nums[i + j] + j;
                    in = i + j;
                }
            }
            i = in;
        }
        return false;
    }
};