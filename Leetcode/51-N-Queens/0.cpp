class Solution {
public:
    vector<string> make_board(vector<int>& state){
        vector<string> board;
        for (int cell : state){
            string line(state.size(), '.');
            line[cell] = 'Q';
            board.push_back(line);
        }
        return board;
    }
    
    void backtracking(
        int level,
        int n,
        vector<int>& state,
        vector<int> & diagonal_left_right,
        vector<int>& diagonal_right_left,
        vector<int>& used_queens,
        vector<vector<string>>& res
    ){
        if (level == n){
            res.push_back(make_board(state));
            return;
        }
        for (int i = 0 ; i < n; ++i){
            if (used_queens[i]) continue;
            if (!diagonal_left_right[i - level + n] && !diagonal_right_left[i + level]){
                diagonal_left_right[i - level + n] = 1;
                diagonal_right_left[i + level] = 1;
                state.push_back(i);
                used_queens[i] = 1;
                backtracking(level + 1, n, state, diagonal_left_right, diagonal_right_left, used_queens,  res);
                diagonal_left_right[i - level + n] = 0;
                diagonal_right_left[i + level] = 0;
                state.pop_back();
                used_queens[i] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> state;
        vector<int> diagonal_left_right(2 * n + 1, 0);
        vector<int> diagonal_right_left(2 * n + 1, 0);
        vector<int> used_queens(n, 0);
        
        backtracking(0, n, state, diagonal_left_right, diagonal_right_left, used_queens, res);
        return res;
    }
};