\*
Author: allannozomu
Runtime: 960 ms
Memory: 20 MB*\

class TicTacToe {
private:
    vector<vector<int>> grid;
    int size;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        grid = vector<vector<int>>(n, vector<int>(n));
        size = n;
    }
    
    int win(int player){
        for (int r = 0 ; r < size; ++r){
            int counter = 0;
            int counter2 = 0;
            for (int c= 0 ; c < size; ++c){
                if (grid[r,c] == player) counter++;
                if (grid[c,r] == player) counter2++;
            }
            if (counter == size || counter2 == size) return player;
        }
        
        int diagonal1 = 0;
        int diagonal2 = 0;
        for (int r = 0 ; r < size; ++r){
            if (grid[r,r] == player) diagonal1++;
            if (grid[r,size - r - 1] == player) diagonal2++;
        }
        if (diagonal1 == size || diagonal2 == size) return player;
        
        return 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        grid[row,col] = player;
        if (win(player)){
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */