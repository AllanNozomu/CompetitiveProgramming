class Solution {
public:
    
    bool dfs (int row, int col, string& word, int level, vector<vector<char>>& board, vector<vector<int>>& visited){
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return false;
        if (visited[row][col]) return false;
        
        if (level == word.size() - 1 && word[level] == board[row][col]) return true;
        if (word[level] != board[row][col]) return false;
        
        visited[row][col] = 1;
        
        bool res = false;
        
        level++;
        res |= dfs(row+1, col, word, level, board, visited);
        res |= dfs(row-1, col, word, level, board, visited);
        res |= dfs(row, col+1, word, level, board, visited);
        res |= dfs(row, col-1, word, level, board, visited);
        
        visited[row][col] = 0;
        return res;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.size() == 0) return {};
        
        unordered_map<char, vector<pair<int, int>>> initial_chars;
        
        for (int i = 0 ; i < board.size(); ++i){
            for (int j = 0; j < board[0].size(); ++j){
                initial_chars[board[i][j]].push_back({i, j});
            }
        }
        
        vector<string> founded_words;
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        for (string word : words){
            for (auto initial_pos : initial_chars[word[0]]){
                if (dfs(initial_pos.first, initial_pos.second, word, 0, board, visited)){
                    founded_words.push_back(word);
                    break;
                }
            }
        }
        return founded_words;
    }
};