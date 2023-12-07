#include <bits/stdc++.h>
class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        vector<vector<int>> ans;
        vector<int> v1;
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());

        for (auto x : s1)
        {
            if (s2.find(x) == s2.end())
            {
                v1.push_back(x);
            }
        }
        ans.push_back(v1);
        v1.clear();
        for (auto x : s2)
        {
            if (s1.find(x) == s1.end())
            {
                v1.push_back(x);
            }
        }
        ans.push_back(v1);

        return ans;
    }
};