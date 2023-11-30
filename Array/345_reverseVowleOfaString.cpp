#include <bits/stdc++.h>
class Solution
{
public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;
        string x = "aeiouAEIOU";
        while (i < j)
        {
            while (i < j && x.find(s[i]) == string::npos)
            {
                i++;
            }
            while (i < j && x.find(s[j]) == string::npos)
            {
                j--;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};