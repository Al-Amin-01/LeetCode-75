#include <bits/stdc++.h>
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0, x = prices[0];
        int n = prices.size();
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, prices[i] - x);
            x = min(x, prices[i]);
        }
        return ans;
    }
};