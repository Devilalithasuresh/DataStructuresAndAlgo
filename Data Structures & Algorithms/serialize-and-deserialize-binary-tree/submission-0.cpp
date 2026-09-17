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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "N";
        string str="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            if(!node)str+="N,";
            else{
                str+=to_string(node->val)+",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return str;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss,val,',');
        if(val=="N") return NULL;
        queue<TreeNode*>q;
        TreeNode* root=new TreeNode(stoi(val));
        q.push(root);
        while(getline(ss,val,',')){
            TreeNode* node=q.front();
            q.pop();
            if(val!="N"){
                TreeNode* newNode=new TreeNode(stoi(val));
                q.push(newNode);
                node->left=newNode;
            }
            getline(ss,val,',');
            if(val!="N"){
                TreeNode*newNode=new TreeNode(stoi(val));
                q.push(newNode);
                node->right=newNode;
            }
        }
        return root;
    }
};
