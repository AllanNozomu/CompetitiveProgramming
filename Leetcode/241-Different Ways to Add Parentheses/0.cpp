class Solution {
public:
    pair<vector<int>, vector<char>> separateNumbersOperations(string& input){
        int number = 0;
        vector<int> numbers;
        vector<char> operations;
        
        for(char c : input){
            if ('0' <= c && c <= '9'){
                number *= 10;
                number += c - '0';
            } else {
                numbers.push_back(number);
                number = 0;
                operations.push_back(c);
            }
        }
        numbers.push_back(number);
        
        return {numbers, operations};
    }
    
    int operate(int num1, char operation, int num2){
        if (operation == '+') return num1+num2;
        if (operation == '-') return num1-num2;
        return num1 * num2;
    }
    
    vector<int> diffWaysToComputeAux(vector<int>& numbers, vector<char>& operations, int start, int end, vector<vector<int>>& visited, vector<vector<vector<int>>>&memo) {
        if (start == end) return  {numbers[start]};
        
        if (visited[start][end]) return memo[start][end];
        
        vector<int> all_res;
        for (int i = 0; start + i <= end - 1; ++i){
            vector<int> curr_res = diffWaysToComputeAux(numbers, operations, start, start + i, visited, memo);
            vector<int> rec_res = diffWaysToComputeAux(numbers, operations, start + i + 1, end, visited, memo);
            for (int res : curr_res){
                for (int res2 : rec_res){
                    all_res.push_back(operate(res, operations[start + i], res2));
                }
            }
        }
        visited[start][end] = 1;
        memo[start][end] = all_res;
        return memo[start][end];
    }
    
    vector<int> diffWaysToCompute(string input) {
        auto numbers_operations = separateNumbersOperations(input);
        vector<vector<int>> visited(numbers_operations.first.size(), vector<int>(numbers_operations.first.size()));
        vector<vector<vector<int>>> memo(numbers_operations.first.size(), vector<vector<int>>(numbers_operations.first.size()));
        
        return diffWaysToComputeAux(numbers_operations.first, numbers_operations.second, 0, numbers_operations.first.size() - 1, visited, memo);
    }
};