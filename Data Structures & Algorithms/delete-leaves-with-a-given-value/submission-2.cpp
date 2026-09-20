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
void solve(TreeNode*root,int target){
    if(!root)return ;
   
    solve(root->left,target);
    solve(root->right,target);
     if(root->left && root->left->val==target && root->left->left==NULL && root->left->right==NULL){
        root->left=NULL;
        return;
    }
    if(root->right && root->right->val==target && root->right->left==NULL && root->right->right==NULL){
        root->right=NULL;
        return;
    }
}
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root)return NULL;
        solve(root,target);
        if(root->val==target && !root->left && !root->right)return NULL;
        return root;
    }
};