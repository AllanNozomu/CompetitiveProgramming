class Solution {
public:
    int numSquares(int n) {
        vector<int> dp = vector<int>(n + 1, 0);
        vector<int> perfect_squares;
        
        dp[1] = 1;
        for(int i = 2; i * i <=n; ++i){
            dp[i*i] = 1;
            perfect_squares.push_back(i*i);
        }
        
        for (int i = 2; i <= n; ++i){
            if (dp[i]) continue;
            dp[i] = dp[i-1] + 1;
            for(int perfect_square : perfect_squares){
                if (i - perfect_square < 1) break;
                dp[i] = min(dp[i], dp[i - perfect_square]+1);
            }
        }
        
        return dp[n];
    }
};