\*
Author: allannozomu
Runtime: 24 ms
Memory: 21.6 MB*\

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int num : nums){
            sum += num;
        }
        
        if (sum < S || -sum > S) return 0;
        
        vector<vector<int>> dp = vector<vector<int>>(nums.size() + 1, vector<int>(2 * sum + 1));
        dp[0,sum] = 1;
        for (int i = 1; i <= nums.size(); ++i ){
            for (int j = 0 ; j < 2 * sum + 1; ++j){
                int num = nums[i - 1];
                if (j + num < 2 * sum + 1){
                    dp[i,j] += dp[i-1,j + num];
                }
                if (j - num >= 0){
                    dp[i,j] += dp[i-1,j - num];
                }
            }
        }
        
        return dp[nums.size(),sum + S];
    }
};