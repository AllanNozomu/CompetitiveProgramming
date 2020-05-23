\*
Author: allannozomu
Runtime: 8 ms
Memory: 9.9 MB*\

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) return 0;
        
        vector<vector<int>> dp;
        for (int i = 0 ; i < triangle.size(); ++i){
            dp.push_back(vector<int>(i + 1));
        }
        
        dp[0,0] = triangle[0,0];
        
        for (int i = 1 ; i < triangle.size(); ++i){
            dp[i,0] = triangle[i,0] + dp[i-1,0];
            for (int j = 1; j < i; ++j){
                dp[i,j] = triangle[i,j] + min(dp[i-1,j - 1], dp[i-1,j]);
            }
            dp[i,i] = triangle[i,i] + dp[i-1,i-1];
        }
        
        int res = dp[dp.size() - 1,0];
        for (int i = 0; i < dp.size(); ++i){
            res = min(res, dp[dp.size() - 1,i]);
        }
        return res;
    }
};