#include <bits/stdc++.h>
class Solution
{
public:
    int call(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i == m && j == n)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int x = 0, y = 0;
        if (i < m)
            x = call(i + 1, j, m, n, dp);
        if (j < n)
            y = call(i, j + 1, m, n, dp);
        return dp[i][j] = x + y;
    }
    int uniquePaths(int m, int n)
    {

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return call(0, 0, m - 1, n - 1, dp);
    }
};