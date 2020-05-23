\*
Author: allannozomu
Runtime: 0 ms
Memory: 8.2 MB*\

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp = vector<int>(n + 1);
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i){
            for (int j = 0; j < i; ++j){
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};