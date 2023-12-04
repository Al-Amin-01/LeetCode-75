#include <bits/stdc++.h>
class Solution
{
public:
    int maxVowels(string s, int k)
    {
        string vowel = "aeiou";
        int x = 0;
        int n = s.size();
        for (int i = 0; i < k; i++)
        {
            if (vowel.find(s[i]) != string::npos)
                x++;
        }
        int ans = x;
        for (int i = k; i < n; i++)
        {
            if (vowel.find(s[i]) != string::npos)
                x++;
            if (vowel.find(s[i - k]) != string::npos)
                x--;
            ans = max(x, ans);
        }
        return ans;
    }
};