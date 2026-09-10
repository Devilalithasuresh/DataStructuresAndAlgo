class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>hash(n+1,0);
       for(auto it:trust){
        int u=it[0];
        int v=it[1];
        hash[v]++;
        if(hash[u]>0)
        hash[u]--;
       }
       int townJudge=-1;
        for(int i=1;i<=n;i++){
            if(hash[i]==n-1){
                townJudge=i;
            }
        }
        return townJudge;
         
    }
};