\*
Author: allannozomu
Runtime: 12 ms
Memory: 11.2 MB*\

class Solution {
public:
    int valid(int row, int col, vector<vector<int>>& visited){
        if (row < 0 || col < 0 || row >= visited.size() || col >= visited[0].size()) 
            return false;
        return !visited[row,col];
    }
    
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& grid){
        if (!valid(row, col, visited)) return;
        if (grid[row,col] != '1') return;
        
        visited[row,col] = 1;
        
        dfs(row + 1, col, visited, grid);
        dfs(row - 1, col, visited, grid); 
        dfs(row, col + 1, visited, grid); 
        dfs(row, col - 1, visited, grid); 
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        
        vector<vector<int>> visited = vector<vector<int>>(grid.size(), vector<int>(grid[0].size()));
        int count = 0;
        
        for (int i = 0 ; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                if (grid[i,j] == '1' && !visited[i,j]){
                    count++;
                    dfs(i,j,visited,grid);
                }
            }
        }
        return count;
    }
};