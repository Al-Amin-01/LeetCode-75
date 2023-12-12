#include <bits/stdc++.h>
class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> chars;
        stack<int> st;
        string res = "";
        int num = 0;
        for (auto c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else if (isalpha(c))
            {
                res.push_back(c);
            }
            else if (c == '[')
            {
                chars.push(res);
                st.push(num);
                res = "";
                num = 0;
            }
            else
            {
                string temp = res;
                for (int i = 0; i < st.top() - 1; i++)
                {
                    res += temp;
                }
                res = chars.top() + res;
                chars.pop();
                st.pop();
            }
        }
        return res;
    }
};