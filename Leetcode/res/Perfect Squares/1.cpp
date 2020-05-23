\*
Author: allannozomu
Runtime: 96 ms
Memory: 11.3 MB*\

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp = vector<int>(n + 1, 0);
        
        dp[1] = 1;
        
        for (int i = 2; i <= n; ++i){
            dp[i] = dp[i-1] + 1;
            for(int j = 2; j * j <=n; ++j){
                int perfect_square = j*j;
                if (i - perfect_square < 0) break;
                dp[i] = min(dp[i], dp[i - perfect_square]+1);
            }
        }
        
        return dp[n];
    }
};