\*
Author: allannozomu
Runtime: 24 ms
Memory: 11.1 MB*\

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        
        vector<vector<int>> dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        int maximumSquare = 0;
        
        for (int i = 0 ; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[0].size(); ++j){
                if (matrix[i,j] == '1'){
                    if (i == 0 || j == 0){
                        dp[i,j] = 1;
                    } else {
                        dp[i,j] = min({dp[i,j-1], dp[i-1,j-1], dp[i-1,j]}) + 1;
                    }
                    maximumSquare = max(maximumSquare, dp[i,j]);
                }
            }
        }
        return maximumSquare * maximumSquare;
    }
};