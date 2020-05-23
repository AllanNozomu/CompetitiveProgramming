\*
Author: allannozomu
Runtime: 44 ms
Memory: 20.3 MB*\

class Solution {
public:
    int valid(int row, int col, vector<vector<int>>& grid){
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return false;
        return grid[row,col];
    }
    
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited, string& code){
        visited[row,col] = 1;
        code.push_back(grid[row,col]);
        
        vector<tuple<int, int, char>> neighbours = {{1, 0, '1'},{-1, 0, '2'},{0, 1, '3'},{0, -1, '4'}};
        for (auto neigh : neighbours){
            int new_row = row + get<0>(neigh), new_col = col + get<1>(neigh);
            if (valid(new_row, new_col, grid) && !visited[new_row,new_col]){
                code.push_back(get<2>(neigh));
                dfs(new_row, new_col, grid, visited, code);
            }
        }
        code.push_back('5');
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        
        unordered_set<string> islands;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int number_of_islands = 0;
        
        for (int i = 0 ; i < grid.size(); ++i){
            for (int j = 0 ; j < grid[0].size(); ++j){
                if (grid[i,j] == 1 && !visited[i,j]){
                    string code = "";
                    dfs(i, j, grid, visited, code);
                    if (islands.find(code) == islands.end()){
                        islands.insert(code);
                        
                        number_of_islands++;
                    }
                }
            }
        }
        return number_of_islands;
    }
};