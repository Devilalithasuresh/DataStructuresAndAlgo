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
TreeNode*Buildtree(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend){
    if(prestart>preend || instart>inend)return NULL;
    int inRoot=mpp[preorder[prestart]];
    int numsLeft=inRoot-instart;
    TreeNode *root=new TreeNode(preorder[prestart]);
    root->left=Buildtree(preorder,prestart+1,prestart+numsLeft,inorder,instart,inRoot-1);
    root->right=Buildtree(preorder,prestart+numsLeft+1,preend,inorder,inRoot+1,inend);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int m=inorder.size();
        if(n!=m)return NULL;
        for(int i=0;i<m;i++){
            mpp[inorder[i]]=i;
        }
        return Buildtree(preorder,0,n-1,inorder,0,m-1);
    }
};
