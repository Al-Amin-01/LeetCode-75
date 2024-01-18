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
    int call(TreeNode *r, int i)
    {
        if (i == 0)
        {
            while (r->right)
            {
                r = r->right;
            }
            return r->val;
        }
        else
        {
            while (r->left)
            {
                r = r->left;
            }
            return r->val;
        }
    }
    int getMinimumDifference(TreeNode *root)
    {
        if (!root)
            return INT_MAX;
        int x = INT_MAX, y = INT_MAX;
        if (root->left)
        {
            x = min(abs(root->val - call(root->left, 0)), getMinimumDifference(root->left));
        }
        if (root->right)
        {
            y = min(abs(root->val - call(root->right, 1)), getMinimumDifference(root->right));
        }
        return min(x, y);
    }
};