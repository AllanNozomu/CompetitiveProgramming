\*
Author: allannozomu
Runtime: 108 ms
Memory: 60.8 MB*\

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums){
            sum += num;
        }
        if (sum % 2) return false;
        
        vector<vector<int>> dp = vector<vector<int>>(nums.size() + 1 , vector<int>(sum / 2 + 1));
        for (int i = 0 ; i < sum / 2 + 1; ++i){
            dp[0,i] = 0;
        }
        
        for (int i = 1 ; i <= nums.size(); ++i){
            for (int j = 1 ; j < sum / 2 + 1; ++j){
                int num = nums[i - 1];
                if (j - num >= 0)
                    dp[i,j] = max(dp[i - 1,j - num] + num, dp[i - 1,j]);
                else
                    dp[i,j] = dp[i - 1,j];
            }
        }

        return (dp[nums.size(),sum / 2] == sum / 2);
        
    }
};