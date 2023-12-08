#include <bits/stdc++.h>
#include <bits/stdc++.h>
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        map<int, int> mp;
        for (auto it : arr)
        {
            mp[it]++;
        }
        set<int> s;
        for (auto it : mp)
        {
            s.insert(it.second);
        }
        if (s.size() == mp.size())
            return true;
        return false;
    }
};