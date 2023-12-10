#include <bits/stdc++.h>
class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        map<vector<int>, int> s;
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j < n; j++)
            {
                v.push_back(grid[i][j]);
            }
            s[v]++;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j < n; j++)
            {
                v.push_back(grid[j][i]);
            }
            if (s.find(v) != s.end())
                cnt += s[v];
        }

        return cnt;
    }
};