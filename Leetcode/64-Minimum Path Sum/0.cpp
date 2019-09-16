class Solution {
public:
    
    int in_bounds(int x, int y, vector<vector<int>>& grid){
        if (x < grid.size() && y < grid[0].size())
            return 1;
        return 0;
    }
    
    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& distances) {
        if (!in_bounds(x, y, grid)){
            return -1;
        }
        if (distances[x][y] >= 0){
            return distances[x][y];
        }
        distances[x][y] = grid[x][y];
        if (x == grid.size() - 1 && y == grid[0].size() - 1){
            return distances[x][y];
        }
        int res_down = dfs(x + 1, y, grid, distances);
        int res_right = dfs(x, y + 1, grid, distances);
        if (res_down >= 0 && res_right >= 0){
            distances[x][y] += min(res_down, res_right);
            return distances[x][y];
        }
        if (res_down >= 0){
            distances[x][y] += res_down;
            return res_down + grid[x][y];
        }
        if (res_right >= 0){
            distances[x][y] += res_right;
            return distances[x][y];
        }
        return -1;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> distances = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1));
        return dfs(0,0, grid, distances);
    }
};