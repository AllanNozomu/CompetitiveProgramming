\*
Author: allannozomu
Runtime: 88 ms
Memory: 44.5 MB*\

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        
        vector<vector<int>> dp = vector<vector<int>>(coins.size() + 1, vector<int>(amount + 1));
        
        for (int i = 1; i <= coins.size(); ++i){
            for (int j = 1; j <= amount; ++j){
                int coin = coins[i - 1];
                if (j - coin == 0){
                    dp[i,j] = 1;
                }else if (j - coin > 0){
                    if (dp[i,j-coin]){
                        if (dp[i-1,j]){
                            dp[i,j] = min(dp[i,j-coin] + 1, dp[i-1,j]);
                        } else {
                            dp[i,j] = dp[i,j-coin] + 1;
                        }
                    } else {
                        dp[i,j] = dp[i-1,j];
                    }
                }else{
                    dp[i,j] = dp[i-1,j];
                }
            }
        }
        
        if (dp[coins.size(),amount]){
            return dp[coins.size(),amount];
        }
        return -1;
    }
};