class Solution {
public:
    
    vector<vector<bool>> visited;
    
    bool in_bounds(int x, int y, const vector<vector<char>>& board){
        if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size()) 
            return true;
        return false;
    }
    
    bool exists(string word, const vector<vector<char>>& board, int x, int y, int pos){
        if (pos == word.size() - 1 && board[x][y] == word[pos]) return true;
        
        visited[x][y] = true;
        if (board[x][y] == word[pos]){
            vector<pair<int, int>> neighbours = {{x,y+1}, {x,y-1}, {x+1,y}, {x-1,y}};
            for (auto neighbour : neighbours){
                if (in_bounds(neighbour.first, neighbour.second, board) && !visited[neighbour.first][neighbour.second] ){
                    if (exists(word, board, neighbour.first, neighbour.second, pos + 1)){
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
        
        vector<pair<int, int>> start_positions(board.size() * board[0].size());
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size()));
        
        int count = 0;
        for (int i = 0 ; i < board.size(); ++i){
            for (int j = 0 ; j < board[0].size(); ++j){
                if (board[i][j] == word[0]){
                    start_positions[count++] = {i,j};
                }
            }
        }
        
        for (pair<int, int> start_position : start_positions){
            cout << start_position.first << " " << start_position.second << endl;
            if (exists(word, board, start_position.first, start_position.second, 0)){
                return true;
            }
        }
        return false;
    }
};