\*
Author: allannozomu
Runtime: 4 ms
Memory: 8.9 MB*\

class Solution {
public:
    void reverse_lines(vector<vector<int>>& matrix){
        for (vector<int> &line : matrix){
            reverse(line.begin(), line.end());
        }
    }
    
    void swap_positions(vector<vector<int>>& matrix){
        int N = matrix.size();
        
        for (int i = 0; i < N- 1; ++i){
            for (int j = 0; j < N - i - 1; ++j){
                int aux = matrix[i,j];
                matrix[i,j] = matrix[N - j - 1,N - i - 1];
                matrix[N - j - 1,N - i - 1] = aux;
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        reverse_lines(matrix);
        swap_positions(matrix);
    }
};