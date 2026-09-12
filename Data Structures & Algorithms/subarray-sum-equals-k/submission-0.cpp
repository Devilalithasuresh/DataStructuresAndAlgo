class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int curSum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            int diff = curSum - k;
            res += prefixSum[diff];
            prefixSum[curSum]++;
        }
        return res;
    }
};