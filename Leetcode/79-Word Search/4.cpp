class Solution {
public:
    
    bool in_bounds(int x, int y, const vector<vector<char>>& board){
        if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size()) 
            return true;
        return false;
    }
    
    bool exists(const string &word, const vector<vector<char>>& board, int x, int y, int pos, vector<vector<bool>>& visited){
        if (pos == word.size() - 1 && board[x][y] == word[pos]) return true;
        
        visited[x][y] = true;
        if (board[x][y] == word[pos]){
            vector<pair<int, int>> neighbours = {{x,y+1}, {x,y-1}, {x+1,y}, {x-1,y}};
            for (auto neighbour : neighbours){
                if (in_bounds(neighbour.first, neighbour.second, board) && !visited[neighbour.first][neighbour.second] ){
                    if (exists(word, board, neighbour.first, neighbour.second, pos + 1, visited)){
                        return true;
                    }
                }
            }
        }
        visited[x][y] = false;
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0) return true;
        if (board.size() == 0 || board[0].size() == 0) return false;
        
        vector<pair<int, int>> start_positions;
        
        for (int i = 0 ; i < board.size(); ++i){
            for (int j = 0 ; j < board[0].size(); ++j){
                if (board[i][j] == word[0]){
                    start_positions.push_back({i,j});
                }
            }
        }
        
        for (pair<int, int> start_position : start_positions){
            vector<vector<bool>> visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size()));
            
            cout << start_position.first << " " << start_position.second << endl;
            if (exists(word, board, start_position.first, start_position.second, 0, visited)){
                return true;
            }
        }
        return false;
    }
};