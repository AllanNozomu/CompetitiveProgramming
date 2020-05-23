\*
Author: allannozomu
Runtime: 16 ms
Memory: 11.7 MB*\

class Solution {
public:
    int valid_pos(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& visited, bool start){
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return false;
        if (visited[x,y]) return false;
        if (!start)
            return grid[x,y] != 2;
        return grid[x,y] == 0;
    }
    
    vector<pair<int, int>> valid_neighbours(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& visited, bool start){
        vector<pair<int, int>> res;
        if (valid_pos(grid, x+1, y, visited, start)){
            res.push_back({x+1, y});
        }
        if (valid_pos(grid, x-1, y, visited, start)){
            res.push_back({x-1, y});
        }
        if (valid_pos(grid, x, y+1, visited, start)){
            res.push_back({x, y+1});
        }
        if (valid_pos(grid, x, y-1, visited, start)){
            res.push_back({x, y-1});
        }
        return res;
    }
    
    int bfs(vector<vector<int>>& grid, int start_x, int start_y, int num_buildings, vector<vector<pair<int, int>>>& hit){
        int count = 0;
        vector<vector<int>> visited = vector<vector<int>>(grid.size(), vector<int>(grid[0].size()));
        queue<pair<int, pair<int, int>>> q;
        
        for (auto neigh : valid_neighbours(grid, start_x, start_y, visited, true)){
            visited[neigh.first,neigh.second] = 1;
            q.push({1, {neigh.first, neigh.second}});
        }
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int distance = front.first;
            int x = front.second.first, y = front.second.second;
            
            if (grid[x,y] == 1){
                num_buildings--;
            } else {
                hit[x,y].first ++;
                hit[x,y].second += distance;
                for (auto neigh : valid_neighbours(grid, x, y, visited, false)){
                    visited[neigh.first,neigh.second] = 1;
                    q.push({distance + 1, {neigh.first, neigh.second}});
                }
            }
        }
        if (num_buildings <= 0) return 1;
        return 0;
    }
    
    int shortestDistance(vector<vector<int>>& grid) {
        int num_buildings = 0;
        vector<pair<int, int>> cities;
        vector<vector<pair<int, int>>> hit = vector<vector<pair<int, int>>>(grid.size(), vector<pair<int, int>>(grid[0].size(), {0,0}));
        
        for (int i = 0 ; i < grid.size(); ++i){
            for(int j = 0 ; j < grid[i].size(); ++j){
                int cell = grid[i,j];
                if (cell == 1){
                    num_buildings++;
                    cities.push_back({i, j});
                }
            }
        }
        for (auto city : cities){
            if (!bfs(grid, city.first, city.second, num_buildings - 1, hit)) return -1;
        }
        int res = -1;
        for (auto line : hit){
            for (auto h : line){
                if (h.first == num_buildings){
                    if (res < 0) res = h.second;
                    else res = min(res, h.second);
                }
            }
        }
        return res;
    }
};