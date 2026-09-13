class Solution {
public:
    int subsetsum(int sum,vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum=0;
        
        for(int i=0;i<nums.size();i++){
            totSum+=nums[i];
        }
        if(totSum<abs(target))return 0;
        if((totSum+target)%2!=0)return 0;
        int sum=(totSum+target)/2;
        return subsetsum(sum,nums);
    }
};