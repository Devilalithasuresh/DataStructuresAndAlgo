class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        vector<int>drow={-1,0,1,0};
        vector<int>dcol={0,1,0,-1};
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        while(!q.empty()){
             auto it=q.top();
             q.pop();
             int diff=it.first;
             int r=it.second.first;
             int c=it.second.second;
             if(r==n-1 && c==m-1)return diff;
            for(int del=0;del<4;del++){
                int nrow=r+drow[del];
                int ncol=c+dcol[del];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                      int newDiff=max(diff,abs(heights[nrow][ncol]-heights[r][c]));
                      if(newDiff<dist[nrow][ncol]){
                        dist[nrow][ncol]=newDiff;
                        q.push({newDiff,{nrow,ncol}});
                      }
                } 
                
            }
        }
        return -1;
        
    }
};