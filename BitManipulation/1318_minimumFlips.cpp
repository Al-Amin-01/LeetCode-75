#include <bits/stdc++.h>
class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int cnt = 0;
        for (int i = 31; i >= 0; i--)
        {
            int x = 1 << i;
            if ((x & c))
            {
                if ((x & a) == 0 && (x & b) == 0)
                    cnt++;
            }
            else
            {
                if ((x & a))
                    cnt++;
                if ((x & b))
                    cnt++;
            }
        }
        return cnt;
    }
};