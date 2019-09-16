class Solution {
private:
    vector<vector<int>> dp;
public:
    int count_bst(int open, int close){
        if (open == 0 && close == 0){
            return 1;
        }
        if (dp[open][close]){
            return dp[open][close];
        }
        int res = 0;
        if (open > 0)
            res += count_bst(open-1, close);
        if (open < close)
            res += count_bst(open, close-1);
        
        dp[open][close] = res;
        return res;
    }
    
    int numTrees(int n) {
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1));
        return count_bst(n,n);
    }
};