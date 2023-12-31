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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        queue<TreeNode *> q;
        if (!root)
            return ans;
        q.push(root);

        while (!q.empty())
        {
            int x = q.size();
            for (int i = 0; i < x; i++)
            {
                TreeNode *p = q.front();
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
                q.pop();
                if (i == x - 1)
                    ans.push_back(p->val);
            }
        }
        return ans;
    }
};