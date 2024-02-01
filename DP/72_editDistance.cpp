#include <bits/stdc++.h>
class Solution
{
public:
    int call(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i == s1.size())
        {
            return s2.size() - j;
        }
        if (j == s2.size())
        {
            return s1.size() - i;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j])
        {
            return dp[i][j] = call(i + 1, j + 1, s1, s2, dp);
        }
        else
        {
            // replace
            int c1 = call(i + 1, j + 1, s1, s2, dp);
            // remove
            int c2 = call(i + 1, j, s1, s2, dp);
            // insert
            int c3 = call(i, j + 1, s1, s2, dp);

            return dp[i][j] = 1 + min(min(c1, c2), c3);
        }
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return call(0, 0, word1, word2, dp);
    }
};