\*
Author: allannozomu
Runtime: 0 ms
Memory: 8.7 MB*\

class Solution {
public:
    int rob(vector<int>& nums) {
        int qty = nums.size();
        if (qty == 0) return 0;
        if (qty == 1) return nums[0];
        if (qty == 2) return max(nums[0], nums[1]);
        
        vector<int> dp = vector<int> (qty);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < qty; ++i){
            dp[i] = max(dp[i-1], nums[i] + dp[i - 2]);
        }
        return dp[qty - 1]; 
    }
};