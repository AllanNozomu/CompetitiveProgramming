class Solution {
public:
    int valid(int row, int col, vector<vector<int>>& rooms){
        if (row < 0 || col < 0 || row >= rooms.size() || col >= rooms[0].size()) return 0;
        return rooms[row][col] == 2147483647;
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.size() == 0) return;
        
        queue<tuple<int, pair<int, int>>> tiles_queue;
        
        for (int i = 0 ; i < rooms.size(); ++i){
            for (int j = 0 ; j < rooms[0].size(); ++j){
                if (rooms[i][j] == 0){
                    tiles_queue.push({0, {i, j}});
                }
            }
        }
        
        while(!tiles_queue.empty()){
            auto curr_node = tiles_queue.front();
            tiles_queue.pop();
            
            int level = get<0>(curr_node);
            int col = get<1>(curr_node).first;
            int row = get<1>(curr_node).second;
            
            if (valid(col+1, row, rooms)){
                rooms[col+1][row] = level + 1;
                tiles_queue.push({level + 1, {col+1, row}});
            }
            if (valid(col-1, row, rooms)){
                rooms[col-1][row] = level + 1;
                tiles_queue.push({level + 1, {col-1, row}});
            }
            if (valid(col, row+1, rooms)){
                rooms[col][row+1] = level + 1;
                tiles_queue.push({level + 1, {col, row+1}});
            }
            if (valid(col, row-1, rooms)){
                rooms[col][row-1] = level + 1;
                tiles_queue.push({level + 1, {col, row-1}});
            }
        }
    }
};