class Solution {
public:
    int isMatch(string s, string p) {
        int dp[s.size() + 1][p.size() + 1] = {};
        
        dp[0][0] = 1;
        
        for (int j = 1; j < p.size(); j += 2){
            if (p[j] == '*' ){
                dp[0][j + 1] = 1;
            } else {
                break;
            }
        }
        
        for (int i = 1; i <= s.size(); ++i){
            for (int j = 1; j <= p.size(); ++j){
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*'){
                    if (s[i-1] != p[j-2] && p[j-2] != '.'){
                        dp[i][j] = dp[i][j-2];
                    } else {
                        dp[i][j] = dp[i][j-1] || dp[i][j-2] || dp[i-1][j];
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};