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
    TreeNode *call(TreeNode *r, int key)
    {
        if (r->left == NULL)
            return r->right;
        if (r->right == NULL)
            return r->left;
        TreeNode *x = r->right;
        TreeNode *y = r->left;
        TreeNode *z = y;
        while (y->right)
            y = y->right;
        y->right = x;
        return z;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val == key)
            return call(root, key);
        TreeNode *r = root;
        while (r)
        {
            if (r->val < key)
            {
                if (r->right && r->right->val == key)
                    r->right = call(r->right, key);
                else
                    r = r->right;
            }
            else
            {
                if (r->left && r->left->val == key)
                    r->left = call(r->left, key);
                else
                    r = r->left;
            }
        }
        return root;
    }
};