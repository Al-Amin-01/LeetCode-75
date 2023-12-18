#include <bits/stdc++.h>
class Solution
{
public:
    void call(int ind, int n, string &x, string &s, map<int, string> &mp, vector<string> &ans)
    {
        if (ind == n)
        {
            ans.push_back(s);
            return;
        }
        int cind = x[ind] - '0';
        for (auto i : mp[cind])
        {
            s.push_back(i);
            call(ind + 1, n, x, s, mp, ans);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        map<int, string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        vector<string> ans;
        string s;
        if (digits.size() == 0)
            return ans;
        call(0, digits.size(), digits, s, mp, ans);
        return ans;
    }
};