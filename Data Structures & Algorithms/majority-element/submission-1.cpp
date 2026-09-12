class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int element=nums[0];
        int freq=0;
        for(int i=0;i<n;i++){
            if(nums[i]==element){
                freq++;
            }
            else{
                freq--;
                if(freq==0){
                    element=nums[i];
                    freq=1;
                }
            }
        }
        return element;
    }
};