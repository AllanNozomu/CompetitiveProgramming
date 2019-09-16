class Solution {
public:
    bool checkLines(vector<vector<char>>& board){
        for (vector<char> line : board){
            vector<int>mapa = vector<int>(9);
            for (char c : line){
                if (c == '.')
                    continue;
                if (mapa[c - '1'] != 0)
                    return false;
                mapa[c - '1'] = 1;
            }
        }
        return true;
    }
    
    bool checkColumns(vector<vector<char>>& board){
        for (int i = 0; i < board.size(); ++i){
            vector<int>mapa = vector<int>(9);
            for(vector<char> line : board){
                char c = line[i];
                if (c == '.')
                    continue;
                if (mapa[c - '1'] != 0)
                    return false;
                mapa[c - '1'] = 1;
            }
        }
        return true;
    }
    
    bool checkSquares(vector<vector<char>>& board){
        for (int row = 0 ; row < board.size() ; row += 3){
            for (int col = 0 ; col < board.size() ; col += 3){
                vector<int>mapa = vector<int>(9);
                for (int i = 0; i < 3; ++i){
                    for (int j = 0 ; j < 3; ++j){
                        char c = board[row + i][col + j];
                        if (c == '.')
                            continue;
                        if (mapa[c - '1'] != 0){
                            return false;
                        }
                        mapa[c - '1'] = 1;
                    }
                }
            }
        }
        return true;
    }
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkLines(board) && checkColumns(board) && checkSquares(board);
    }
};