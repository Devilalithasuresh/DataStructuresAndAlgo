class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int n=nums.size();
      int longest=0;
      set<int>st(nums.begin(),nums.end());
      for(int i=0;i<n;i++){
        if(st.find(nums[i]-1)==st.end()){
            int length=0;
            while(st.find(nums[i]+length)!=st.end()){
                length++;
            }
            longest=max(longest,length);
        }
      }
      return longest;
    }
};
