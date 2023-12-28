#include<bits/stdc++.h>
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
class Solution {
public:
    int ans=0;
    set<TreeNode*> s;
    void call(TreeNode* r,long long sum,int target){
        if(r==NULL) return;
        sum=sum+r->val;
        if(sum==target){
            ans++;
        }
        s.insert(r);
        
        if(s.find(r->left)==s.end()) call(r->left,0,target);
        if(s.find(r->right)==s.end()) call(r->right,0,target);
        call(r->left,sum,target);
        call(r->right,sum,target);
        


    }
    int pathSum(TreeNode* root, int targetSum) {
        s.insert(root);
        call(root,0,targetSum);
        return ans;
    }
};