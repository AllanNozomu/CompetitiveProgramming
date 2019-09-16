class Solution {
public:
    int multiplyElement(vector<vector<int>>& A, int row, vector<vector<int>>& B, int col){
        int res = 0;
        for (int i = 0 ; i < B.size(); ++i){
            res += A[row][i] * B[i][col];
        }
        return res;
    }
    
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (B.size() == 0) return {};
        
        int rows = A.size();
        int cols = B[0].size();

        vector<vector<int>> res = vector<vector<int>>(rows, vector<int>(cols));
        
        for (int r = 0; r < rows; ++r){
            for (int c = 0; c < cols; ++c){
                res[r][c] = multiplyElement(A, r, B, c);
            }
        }
        return res;
    }
};