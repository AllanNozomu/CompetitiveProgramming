\*
Author: allannozomu
Runtime: 72 ms
Memory: 21.7 MB*\

class Solution {
public:
    
    int valid(int row, int col, vector<vector<int>>& matrix, int previous){
        if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size()){
            return 0;
        }
        return matrix[row,col] > previous;
    }
    
    int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& memo){
        int longestPath = 1;
        
        if (memo[row,col]) return memo[row,col];
        
        vector<pair<int, int>> neighbours = {{row+1, col},{row-1, col},{row, col+1},{row, col-1}};
        for (pair<int, int> neighbour : neighbours){
            if (valid(neighbour.first, neighbour.second, matrix, matrix[row,col])){
                longestPath = max(longestPath, 1 + dfs(neighbour.first, neighbour.second, matrix, memo));
            }
        }
        memo[row,col] = longestPath;
        return longestPath;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        
        int longestPath = 0;
        vector<vector<int>> memo = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));
        
        for (int i = 0 ; i< matrix.size(); ++i){
            for (int j = 0; j < matrix[0].size(); ++j){
                longestPath = max(longestPath, dfs(i, j, matrix, memo));
            }
        }
        return longestPath;
    }
};