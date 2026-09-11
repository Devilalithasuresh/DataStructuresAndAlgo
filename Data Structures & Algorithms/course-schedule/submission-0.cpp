class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int>ans;
       vector<int>indegree(numCourses,0);
       vector<vector<int>>adj(numCourses);
       for(auto it:prerequisites){
        int a=it[0];
        int b=it[1];
        adj[b].push_back(a);
        indegree[a]++;
       }
       queue<int>q;
       for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
            q.push(i);
        }
       }
       while(!q.empty()){

        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
       }
       return ans.size()==numCourses;

    }
};
