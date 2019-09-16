class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& memo){
        if (i > grid.size() || j > grid[0].size()) return 0;
        if (grid[i-1][j-1] == 1) return 0;
        if (i == grid.size() && j == grid[0].size()) return 1;
        
        if (memo[i][j] == -1)
            memo[i][j] = dfs(i + 1, j, grid, memo) + dfs(i, j + 1, grid, memo);
        
        return memo[i][j];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0) return 0;
        
        vector<vector<int>> memo(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1, -1));
        return dfs(1, 1, obstacleGrid, memo);
        
    }
};