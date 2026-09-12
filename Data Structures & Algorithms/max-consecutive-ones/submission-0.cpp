class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCnt=0;
        int i=0;
        int cnt=0;
       
        for(i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
            }
            else{
                maxCnt=max(maxCnt,cnt);
                cnt=0;
            }
        }
        maxCnt=max(maxCnt,cnt);
        return maxCnt;
    }
};