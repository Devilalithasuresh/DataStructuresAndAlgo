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
int height(TreeNode* node,int & maxDiff){
    if(!node)return 0;
    int left=height(node->left,maxDiff);
    int right=height(node->right,maxDiff);
    maxDiff=max(maxDiff,abs(left-right));
    return 1+max(left,right);
}
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        int maxDiff=0;
        height(root,maxDiff);
        return maxDiff<=1;
    }
};
