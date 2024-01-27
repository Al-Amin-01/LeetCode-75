#include <bits/stdc++.h>
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), cmp);
        int ans = 0, n = points.size(), y = points[0][1];
        for (int i = 1; i < n; i++)
        {
            if (points[i][0] <= y)
            {
                ans++;
            }
            else
            {
                y = points[i][1];
            }
        }
        return n - ans;
    }
};