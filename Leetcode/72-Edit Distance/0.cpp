class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0 || word2.size() == 0) return max(word1.size(), word2.size());
        
        int dp[word1.size() + 1][word2.size() + 1] = {};
        
        for (int j = 1; j <= word2.size(); ++j){
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); ++i){
            dp[i][0] = i;
            for (int j = 1; j <= word2.size(); ++j){
                if (word1[i - 1] == word2[j - 1]){
                    dp[i][j] = min({dp[i-1][j-1] - 1, dp[i-1][j], dp[i][j-1]}) + 1;
                } else {
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};