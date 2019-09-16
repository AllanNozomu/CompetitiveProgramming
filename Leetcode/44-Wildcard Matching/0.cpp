class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp = vector<vector<bool>>(s.size() + 1, vector<bool>(p.size() + 1));
        dp[0][0] = 1;
        
        int np = p.size();
        int ns = s.size();
        
        for(int j = 1; j <= np; j++) {
            if(p[j-1] == '*'){
                dp[0][j] = 1;
            } else {
                break;
            }
        }
        
        for (int i = 1; i <= ns; ++i){
            for (int j = 1; j <= np; ++j){
                if (p[j-1] == '?' || s[i-1] ==  p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i-1][j-1];
                }
            }
        }
     
        return dp[ns][np];
    }
};