class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>>& memo){
        if (i > m || j > n) return 0;
        if (i == m && j == n) return 1;
        
        if (!memo[i][j])
            memo[i][j] = dfs(i + 1, j, m, n, memo) + dfs(i, j + 1, m, n, memo);
        
        return memo[i][j];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
        return dfs(1, 1, m, n, memo);
    }
};