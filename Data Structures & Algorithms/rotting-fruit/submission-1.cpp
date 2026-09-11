class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int count=0;
        int n=grid.size();
        int m=grid[0].size();
        
       vector<vector<int>>vis(n,vector<int>(m,0));
       queue<pair<pair<int,int>,int>>q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=1;
            }
        }
       } 
       int drow[]={-1,0,1,0};
       int dcol[]={0,1,0,-1};
       while(!q.empty()){
          int time=q.front().second;
          auto [r, c]=q.front().first;
          q.pop();
          for(int del=0;del<4;del++){
            int nrow=r+drow[del];
            int ncol=c+dcol[del];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                vis[nrow][ncol]=1;
                grid[nrow][ncol]=2;
                q.push({{nrow,ncol},time+1});
                count=max(count,time+1);
            }
          }
       }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)return -1;
        }
       }
       return count;
    }
};
 
    