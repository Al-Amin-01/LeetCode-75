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
    int ans;
    void call(TreeNode *r, int &k)
    {

        if (r->left)
            call(r->left, k);
        k--;
        if (k == 0)
        {
            ans = r->val;
            return;
        }
        if (r->right)
            call(r->right, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {

        call(root, k);
        return ans;
    }
};