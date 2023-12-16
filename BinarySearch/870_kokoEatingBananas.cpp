#include <bits/stdc++.h>
class Solution
{
public:
    long long call(vector<int> &piles, int x)
    {
        long long cnt = 0;
        for (auto a : piles)
        {
            cnt += a / x;
            if (a % x)
                cnt++;
        }
        return cnt;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int l = 1, r = 1e9, mid;

        while (l < r)
        {
            mid = (l + r) / 2;
            if (call(piles, mid) > h)
            {
                l = mid + 1;
            }
            else
                r = mid;
        }
        if (call(piles, l) >= h)
            return l;
        else
            return r;
    }
};