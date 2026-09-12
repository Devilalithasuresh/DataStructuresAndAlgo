class Solution {
public:
    bool check(vector<int>& nums) {
       int breakpoint=0;
       int n=nums.size();
       for(int i=0;i<nums.size();i++){
        if(nums[i]>nums[(i+1)%n]){
            if(!breakpoint)breakpoint=1;
            else return false;
        }
       } 
       return true;
    }
};