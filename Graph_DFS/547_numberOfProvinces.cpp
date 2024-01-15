#include <bits/stdc++.h>
class Solution
{
public:
    void call(int ind, vector<int> v[], vector<int> &vis)
    {
        for (auto x : v[ind])
        {
            if (vis[x] == 0)
            {
                vis[x] = 1;
                call(x, v, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> v[n];
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> w;
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j])
                    w.push_back(j);
            }
            v[i] = w;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                cnt++;
                vis[i] = 1;
                call(i, v, vis);
            }
        }
        return cnt;
    }
};