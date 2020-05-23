\*
Author: allannozomu
Runtime: 24 ms
Memory: 15.6 MB*\

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) return true;
        
        int dp[s.size() + 1] = {0};
        
        sort(wordDict.begin(), wordDict.end());

        dp[0] = 1;
        for (int i = 0; i < s.size(); ++i){
            for (int j = 1; i + j <= s.size(); ++j) {
                if (binary_search(wordDict.begin(), wordDict.end(), s.substr(i, j))){
                    dp[i + j] |= dp[i];
                }
            }
        }
        return dp[s.size()];
    }
};