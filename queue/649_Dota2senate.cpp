#include <bits/stdc++.h>
class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int n = senate.size();
        queue<int> r, d;
        for (int i = 0; i < n; i++)
        {
            if (senate[i] == 'D')
                d.push(i);
            else
                r.push(i);
        }
        while (!d.empty() && !r.empty())
        {
            if (d.front() < r.front())
            {
                d.push(n++);
            }
            else
            {
                r.push(n++);
            }
            d.pop();
            r.pop();
        }
        if (d.empty())
            return "Radiant";
        else
            return "Dire";
    }
};