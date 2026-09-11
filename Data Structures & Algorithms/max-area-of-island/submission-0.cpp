class Solution {
public:
int maxCount=0;
void bfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis){
    vector<int>drow={-1,0,1,0};
    vector<int>dcol={0,1,0,-1};
    int count=1,n=grid.size(),m=grid[0].size();
    queue<pair<int,int>>q;
    q.push({row,col});
    vis[row][col]=1;
    while(!q.empty()){
        auto [r, c]=q.front();
        q.pop();
        for(int del=0;del<4;del++){
            int nrow=r+drow[del];
            int ncol=c+dcol[del];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                count++;
                vis[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
    maxCount=max(maxCount,count);

}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    bfs(i,j,grid,vis);
                }
            }
        }
        return maxCount;
    }
};
