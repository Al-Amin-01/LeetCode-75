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
    int maxLen = 0;
    void call(TreeNode *r, int dir, int curLen)
    {
        if (!r)
            return;
        maxLen = max(maxLen, curLen);
        call(r->left, 0, dir == 0 ? 1 : curLen + 1);
        call(r->right, 1, dir == 1 ? 1 : curLen + 1);
    }
    int longestZigZag(TreeNode *root)
    {
        call(root, 0, 0);
        call(root, 1, 0);
        return maxLen;
    }
};