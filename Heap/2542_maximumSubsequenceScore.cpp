#include <bits/stdc++.h>
class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; i++)
        {
            vp[i] = {nums2[i], nums1[i]};
        }
        sort(vp.rbegin(), vp.rend());
        long long ans = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k - 1; i++)
        {
            sum += vp[i].second;
            pq.push(vp[i].second);
        }

        for (int i = k - 1; i < n; i++)
        {
            sum += vp[i].second;
            ans = max(ans, sum * vp[i].first);
            pq.push(vp[i].second);
            sum -= pq.top();
            pq.pop();
        }
        return ans;
    }
};