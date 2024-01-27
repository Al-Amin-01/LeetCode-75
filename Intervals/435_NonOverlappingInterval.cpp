#include <bits/stdc++.h>
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
class Solution
{

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        int y = intervals[0][1];

        int res = 0;
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] < y)
                res++;
            else
            {
                y = intervals[i][1];
            }
        }

        return res;
    }
};