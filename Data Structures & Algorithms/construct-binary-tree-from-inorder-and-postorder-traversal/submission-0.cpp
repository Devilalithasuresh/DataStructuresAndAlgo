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
map<int,int>mpp;
TreeNode* Buildtree(vector<int>&postorder,int poststart,int postend,vector<int>&inorder,int instart,int inend){
    if(poststart>postend||instart>inend){
        return NULL;
    }
    int inRoot=mpp[postorder[postend]];
    int numsLeft=inRoot-instart;
    TreeNode*root=new TreeNode(postorder[postend]);
    root->left=Buildtree(postorder,poststart,poststart+numsLeft-1,inorder,instart,inRoot-1);
    root->right=Buildtree(postorder,poststart+numsLeft,postend-1,inorder,inRoot+1,inend);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        int m=inorder.size();
        if(n!=m)return NULL;
        for(int i=0;i<m;i++){
            mpp[inorder[i]]=i;
        }
        return Buildtree(postorder,0,n-1,inorder,0,m-1);
    }
};