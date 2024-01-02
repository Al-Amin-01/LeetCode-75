#include <bits/stdc++.h>
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        int n = costs.size();
        long long ans = 0;
        if (candidates * 2 >= n || n == k)
        {
            sort(costs.begin(), costs.end());
            int i = 0;
            while (k--)
            {
                ans += costs[i++] + 0LL;
            }
        }
        else
        {
            int i = 0, j = n - 1;
            multiset<int> s1, s2;
            while (i < candidates)
            {
                s1.insert(costs[i]);
                i++;
            }
            int x = candidates;
            while (x--)
            {
                s2.insert(costs[j--]);
            }
            while (k--)
            {
                auto r1 = s1.begin();
                auto r2 = s2.begin();
                if (s1.empty() || (*r1) > (*r2))
                {
                    ans += (*r2) + 0LL;
                    s2.erase(r2);
                    if (j >= i)
                    {
                        s2.insert(costs[j]);
                        j--;
                    }
                }
                else
                {
                    ans += (*r1) + 0LL;
                    s1.erase(r1);
                    if (j >= i)
                    {
                        s1.insert(costs[i]);
                        i++;
                    }
                }
            }
        }
        return ans;
    }
};