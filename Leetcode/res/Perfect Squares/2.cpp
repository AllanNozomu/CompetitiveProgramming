\*
Author: allannozomu
Runtime: 96 ms
Memory: 11.4 MB*\

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp = vector<int>(n + 1, 0);
        
        dp[1] = 1;
        for(int i = 2; i * i <=n; ++i){
            dp[i*i] = 1;
        }
        
        for (int i = 2; i <= n; ++i){
            if (dp[i]) continue;
            dp[i] = dp[i-1] + 1;
            for(int j = 2; j * j <=n; ++j){
                int perfect_square = j*j;
                if (i - perfect_square < 1) break;
                dp[i] = min(dp[i], dp[i - perfect_square]+1);
            }
        }
        
        return dp[n];
    }
};