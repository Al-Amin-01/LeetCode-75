#include <bits/stdc++.h>
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int i = 0, cnt = 0;
        int n = nums.size();
        while (i < n)
        {
            if (n == 1)
                break;
            cnt++;
            if (nums[i] >= n - 1 - i)
                break;
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
        return cnt;
    }
};