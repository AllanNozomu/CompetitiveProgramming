\*
Author: allannozomu
Runtime: 0 ms
Memory: 8.8 MB*\

class Solution {
public:
    int valid(int row, int col, vector<vector<int>>& board){
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()){
            return 0;
        }
        return 1;
    }
    
    int isAlive(pair<int, int>& neighbour, vector<vector<int>>& board){
        int row = neighbour.first, col = neighbour.second;
        if (valid(row, col, board)){
            switch (board[row,col]) {
                case 1: 
                    return 1; break;
                case -2:
                    return 1; break;
            }
            return 0;
        }
        return 0;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() == 0) return;
        
        for (int i = 0 ; i < board.size(); ++i){
            for (int j = 0 ; j < board[0].size(); ++j){
                vector<pair<int, int>> neighbours = {
                    {i-1, j-1},{i-1,j},{i-1, j+1},
                    {i, j-1},{i, j+1},
                    {i+1, j-1},{i+1, j},{i+1, j+1}
                };
                int living_neighbour = 0;
                for (pair<int, int> neighbour : neighbours){
                    if (isAlive(neighbour, board)){
                        living_neighbour++;
                    }
                }
                
                if (board[i,j]){
                    if (living_neighbour != 2 && living_neighbour != 3) 
                        board[i,j] = -2;
                } else {
                    if (living_neighbour == 3) 
                        board[i,j] = -1;
                }
            }   
        }
        for (int i = 0 ; i < board.size(); ++i){
            for (int j = 0 ; j < board[0].size(); ++j){
                if (board[i,j] == -2)
                    board[i,j] = 0;
                else if (board[i,j] == -1)
                    board[i,j] = 1;
            }
        }
    }
};