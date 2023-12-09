#include <bits/stdc++.h>
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        vector<int> w1(26, 0);
        vector<int> w2(26, 0);
        int n1 = word1.size(), n2 = word2.size();
        if (n1 != n2)
            return false;
        for (int i = 0; i < n1; i++)
        {
            w1[word1[i] - 'a']++;
            w2[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (w1[i] != w2[i] && w1[i] && w2[i])
            {
                for (int j = i + 1; j < 26; j++)
                {
                    if (w1[i] == w2[j])
                    {

                        swap(w2[i], w2[j]);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (w1[i] != w2[i])
                return false;
        }
        return true;
    }
};