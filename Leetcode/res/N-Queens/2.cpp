\*
Author: allannozomu
Runtime: 184 ms
Memory: 118 MB*\

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
    
    vector<vector<string>> solveNQueens(int n) {
        vector<int> state(n);
        vector<vector<string>> res;
        
        for (int i = 0 ; i < n; ++i){
            state[i] = i;
        }
        
        do {
            vector<int> diagonal_left_right(n * 2 + 1, 0);
            vector<int> diagonal_right_left(n * 2 + 1, 0);
            bool valid = true;
            
            for (int i = 0 ; i < n && valid; ++i){
                int cell = state[i];
                if (!diagonal_left_right[i - cell + n]){
                    diagonal_left_right[i - cell + n] = 1;
                } else valid = false;
                if (!diagonal_right_left[i + cell]){
                    diagonal_right_left[i + cell] = 1;
                } else valid = false;
            }
            if (valid)
                res.push_back(make_board(state));
                
        } while(next_permutation(state.begin(), state.end()));
        
        return res;
    }
};