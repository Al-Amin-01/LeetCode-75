#include <bits/stdc++.h>
class Solution
{
public:
    int dfs(int from, vector<vector<int>> &v, vector<bool> &vis)
    {
        int ans = 0;
        vis[from] = true;
        for (auto to : v[from])
        {
            if (!vis[abs(to)])
            {
                ans += dfs(abs(to), v, vis) + (to > 0);
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> v(n);
        for (int i = 0; i < connections.size(); i++)
        {
            v[connections[i][0]].push_back(connections[i][1]);
            v[connections[i][1]].push_back(-connections[i][0]);
        }
        vector<bool> vis(n, false);
        return dfs(0, v, vis);
    }
};