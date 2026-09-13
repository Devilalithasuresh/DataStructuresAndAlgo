class Solution {
public:
int paths(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid){
    if(i==0 && j==0)return 1;
    if(i<0 || j<0)return 0;
    if(grid[i][j]==1)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int up=paths(i-1,j,dp,grid);
    int left=paths(i,j-1,dp,grid);
    return dp[i][j]=up+left;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1 || obstacleGrid[0][0]==1)return 0; 
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return paths(n-1,m-1,dp,obstacleGrid);
    }
};