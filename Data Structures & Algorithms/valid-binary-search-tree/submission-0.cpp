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
bool validate(TreeNode*root,int minval,int maxval){
    if(root==NULL)return true;
    if(root->val<=minval || root->val>=maxval)return false;
    return validate(root->left,minval,root->val) && validate(root->right,root->val,maxval);
}
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        return validate(root,INT_MIN,INT_MAX);
    }
};
