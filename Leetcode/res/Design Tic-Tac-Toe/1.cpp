\*
Author: allannozomu
Runtime: 28 ms
Memory: 20 MB*\

class TicTacToe {
private:
    vector<int> row_counter_1;
    vector<int> row_counter_2;
    vector<int> col_counter_1;
    vector<int> col_counter_2;
    
    int diagonal1_1, diagonal2_1;
    int diagonal1_2, diagonal2_2;
    int size;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        row_counter_1 = vector<int>(n);
        row_counter_2 = vector<int>(n);
        col_counter_1 = vector<int>(n);
        col_counter_2 = vector<int>(n);
        
        diagonal1_1 = diagonal2_1 = 0;
        diagonal1_2 = diagonal2_2 = 0;
        size = n;
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
        if (player == 1){
            row_counter_1[row]++;
            col_counter_1[col]++;
            if (row == col){
                diagonal1_1++;
            }
            if (row == size - 1 - col){
                diagonal2_1++;
            }
            if (row_counter_1[row] == size || col_counter_1[col] == size || diagonal1_1 == size || diagonal2_1 == size) return 1;
        } else {
            row_counter_2[row]++;
            col_counter_2[col]++;
            if (row == col){
                diagonal1_2++;
            }
            if (row == size - 1 - col){
                diagonal2_2++;
            }
            if (row_counter_2[row] == size || col_counter_2[col] == size || diagonal1_2 == size || diagonal2_2 == size) return 2;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */