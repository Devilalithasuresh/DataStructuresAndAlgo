class Solution {
public:

bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&parent){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            parent[it]=node;
            if(!dfs(it,adj,vis,parent))return false;
        }
        else{
            if(it!=parent[node])return false;
        }
    }
    return true;
}
    bool validTree(int n, vector<vector<int>>& edges) {
         vector<vector<int>>adj(n);
         vector<int>parent(n,-1);
         parent[0]=0;
         for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
         }
         vector<int>vis(n,0);
         if(dfs(0,adj,vis,parent)==false)return false;
         for(int i=1;i<n;i++){
            if(!vis[i]){
              return false;
            }
         }
         return true;
         
    }
};
