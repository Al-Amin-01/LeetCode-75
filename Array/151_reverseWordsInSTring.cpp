#include <bits/stdc++.h>
class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            while (i < n && s[i] == ' ')
                i++;
            string w = "";
            while (i < n && s[i] != ' ')
            {
                w += s[i];
                i++;
            }
            if (w != "")
                v.push_back(w);
        }
        string ans = "";
        for (int i = v.size() - 1; i >= 0; i--)
        {
            ans += v[i];
            if (i != 0)
                ans += " ";
        }

        return ans;
    }
};