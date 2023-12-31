#include <bits/stdc++.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        int ind = -1, sum = INT_MIN;
        queue<TreeNode *> q;
        q.push(root);
        int level = 1;
        while (!q.empty())
        {
            int x = q.size();
            int cur = 0;
            for (int i = 0; i < x; i++)
            {
                TreeNode *p = q.front();
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
                cur += p->val;
                q.pop();
            }
            if (cur > sum)
            {
                ind = level;
                sum = cur;
            }
            level++;
        }
        return ind;
    }
};