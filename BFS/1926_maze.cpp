#include <bits/stdc++.h>
class Solution
{
public:
    int ans = -1;
    int xl = 0, yl = 0;
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        xl = entrance[0];
        yl = entrance[1];
        queue<pair<pair<int, int>, int>> q;
        q.push({{xl, yl}, 0});
        visited[xl][yl] = 1;
        int ex[4] = {-1, 0, 1, 0};
        int ey[4] = {0, -1, 0, 1};
        while (!q.empty())
        {
            int len = q.size();
            for (int j = 0; j < len; j++)
            {
                int x = q.front().first.first;
                int y = q.front().first.second;
                int c = q.front().second;
                if (x == n - 1 || y == m - 1 || x == 0 || y == 0)
                {
                    if (x != xl || y != yl)
                        return c;
                }
                q.pop();
                int xx, yy;
                for (int k = 0; k < 4; k++)
                {
                    xx = x + ex[k];
                    yy = y + ey[k];
                    if (xx < n && xx >= 0 && yy < m && yy >= 0 && visited[xx][yy] != 1 && maze[xx][yy] == '.')
                    {
                        q.push({{xx, yy}, c + 1});
                        visited[xx][yy] = 1;
                    }
                }
            }
        }

        return -1;
    }
};