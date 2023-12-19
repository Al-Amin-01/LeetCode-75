#include <bits/stdc++.h>
class Solution
{
public:
    int mod = 1e9 + 7;
    int call(int n, vector<int> &dp)
    {
        if (n <= 3)
            return dp[n];
        if (dp[n] != 0)
            return dp[n];
        long long x = call(n - 1, dp) % mod;
        long long y = call(n - 3, dp) % mod;
        return dp[n] = ((2 * x) % mod + y % mod) % mod;
    }
    int numTilings(int n)
    {
        vector<int> dp(n + 1, 0);
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        return call(n, dp);
    }
};