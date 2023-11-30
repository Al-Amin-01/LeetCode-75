#include <bits/stdc++.h>
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int ans = 0;
        int n = chars.size();
        int k = 0;

        for (int i = 0; i < n;)
        {
            char c = chars[i];
            int cnt = 0;

            while (i < n && chars[i] == c)
            {
                cnt++;
                i++;
            }
            ans++;
            chars[k++] = c;
            if (cnt > 1)
            {
                vector<int> v;
                while (cnt)
                {
                    ans++;
                    v.push_back(cnt % 10);
                    cnt /= 10;
                }
                reverse(v.begin(), v.end());
                for (int j = 0; j < v.size(); j++)
                {
                    chars[k] = char(v[j] + 48);
                    k++;
                }
            }
        }
        return ans;
    }
};